/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_initializer_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 21:15:41 by arobu             #+#    #+#             */
/*   Updated: 2023/02/19 22:11:48 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/state.h"

static void	initialize_fork_values(t_state *state);

void	state_initializer_utils(t_state *state, int argc, char **argv)
{
	int	i;

	i = -1;
	initialize_rules(state, argc);
	state->rules = state->init_rules(argv);
	state->philosophers = (t_philosopher *)malloc(sizeof(t_philosopher) * \
		state->rules.number_of_philosophers);
	if (!state->philosophers)
		state_exit_error(state);
	state->forks = (t_fork *)malloc(sizeof(t_fork) * \
		state->rules.number_of_philosophers);
	if (!state->forks)
		state_exit_error(state);
	state->writing = malloc(sizeof(pthread_mutex_t));
	if (!state->writing)
		state_exit_error(state);
	return ;
}

void	init_state_values(t_state *state)
{
	initialize_fork_values(state);
	state->are_synced = 0;
	state->is_dead = 0;
	state->is_finished = 0;
	pthread_create(&state->sync_thread, NULL, sync_threads, state);
	pthread_detach(state->sync_thread);
	pthread_mutex_init(state->writing, NULL);
}

void	state_exit_error(t_state *state)
{
	printf("Error: %s\n", strerror(errno));
	if (state->philosophers)
		free(state->philosophers);
	if (state->forks)
		free(state->forks);
	if (state->writing)
		pthread_mutex_destroy(state->writing);
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
