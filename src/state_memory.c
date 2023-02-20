/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 00:12:33 by arobu             #+#    #+#             */
/*   Updated: 2023/02/21 00:12:41 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/state.h"

void	finish_and_free_resources(t_state *state)
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
