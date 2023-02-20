/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_initializer_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 21:15:41 by arobu             #+#    #+#             */
/*   Updated: 2023/02/20 22:39:50 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/state.h"

static void	initialize_fork_values(t_state *state);
static void	create_and_detach(pthread_t *thread, void *(*function)(void *), \
							void *arg);

void	state_initializer_utils(t_state **state, int argc, char **argv)
{
	bool	are_valid;

	are_valid = true;
	initialize_rules(*state, argc);
	(*state)->rules = (*state)->init_rules(argv);
	rules_checker((*state)->rules, argc, &are_valid);
	if (!are_valid)
		print_and_exit(*state);
	(*state)->philosophers = (t_philosopher *)malloc(sizeof(t_philosopher) * \
		(*state)->rules.number_of_philosophers);
	if (!(*state)->philosophers)
		state_exit_error((*state));
	(*state)->forks = (t_fork *)malloc(sizeof(t_fork) * \
		(*state)->rules.number_of_philosophers);
	if (!(*state)->forks)
		state_exit_error((*state));
	(*state)->writing = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	if (!(*state)->writing)
		state_exit_error((*state));
	(*state)->death_mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	if (!(*state)->death_mutex)
		state_exit_error((*state));
	return ;
}

void	init_state_values(t_state *state)
{
	initialize_fork_values(state);
	state->thread_started = 0;
	state->are_synced = 0;
	state->dinner_over = 0;
	state->is_finished = 0;
	state->dt_started = 0;
	state->cm_started = 1;
	create_and_detach(&state->sync_thread, sync_threads, state);
	create_and_detach(&state->check_death_thread, check_death, state);
	if (state->rules.times_must_eat != -1)
	{
		create_and_detach(&state->check_meals_thread, check_meals, state);
		state->cm_started = 0;
	}
}

void	state_exit_error(t_state *state)
{
	printf("Error: %s\n", strerror(errno));
	if (state->philosophers)
		free(state->philosophers);
	if (state->forks)
		free(state->forks);
	if (state->writing)
	{
		pthread_mutex_destroy(state->writing);
		free(state->writing);
	}
	if (state->death_mutex)
	{
		pthread_mutex_destroy(state->death_mutex);
		free(state->death_mutex);
	}
	if (state)
		free(state);
	exit(1);
}

static void	initialize_fork_values(t_state *state)
{
	int	i;
	int	j;

	i = -1;
	while (++i < state->rules.number_of_philosophers)
	{
		if (pthread_mutex_init(&state->forks[i].mutex, NULL) != 0)
		{
			j = -1;
			while (++j < i)
				pthread_mutex_destroy(&state->forks[j].mutex);
			state_exit_error(state);
		}
		state->forks[i].id = i;
	}
}

static void	create_and_detach(pthread_t *thread, void *(*function)(void *), \
							void *arg)
{
	pthread_create(thread, NULL, function, arg);
	pthread_detach(*thread);
}
