/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 18:29:35 by arobu             #+#    #+#             */
/*   Updated: 2023/02/21 00:08:16 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "philosophers.h"
#include "state.h"

static void	finish_and_free_resources(t_state *state);

int	main(int argc, char **argv)
{
	t_state			*state;
	int				i;

	state = NULL;
	i = -1;
	initialize_state(&state, argc, argv);
	initialize_philo(state);
	state->thread_started = 1;
	pthread_mutex_unlock(state->death_mutex);
	finish_and_free_resources(state);
	return (0);
}

static void	finish_and_free_resources(t_state *state)
{
	int		i;

	i = -1;
	while (++i < state->rules.number_of_philosophers && \
		state->rules.number_of_philosophers > 1)
		pthread_join(state->philosophers[i].thread, (NULL));
	while (!state->dinner_over && !state->is_finished && \
			state->rules.number_of_philosophers == 1)
		usleep(100);
	i = -1;
	while (++i < state->rules.number_of_philosophers)
		pthread_mutex_destroy(&state->forks[i].mutex);
	pthread_mutex_lock(state->death_mutex);
	pthread_mutex_unlock(state->death_mutex);
	pthread_mutex_destroy(state->writing);
	pthread_mutex_destroy(state->death_mutex);
	free(state->writing);
	free(state->death_mutex);
	free(state->philosophers);
	free(state->forks);
	free(state);
}

