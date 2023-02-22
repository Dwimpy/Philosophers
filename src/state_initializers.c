/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_initializers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 18:54:07 by arobu             #+#    #+#             */
/*   Updated: 2023/02/22 06:29:20 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/state.h"
#include <stdio.h>
#include <stdbool.h>

t_state	*init_state(int argc, char **argv)
{
	t_state	*state;

	check_args(argc, argv);
	state = (t_state *)allocate_state_memory((void **)&state, sizeof(t_state));
	set_null_values(&state);
	set_init_rules(&state, argc, argv);
	allocate_state_members(&state);
	return (state);
}

void	allocate_state_members(t_state **state_var)
{
	t_state		*state;

	state = *state_var;
	state->philos = (t_philo *)allocate_memory_nelem((void **)&state->philos,
			sizeof(t_philo), state->rules.n_philo);
	state->forks = (pthread_mutex_t *)allocate_memory_nelem((void **) \
				&state->forks, sizeof(pthread_mutex_t), state->rules.n_philo);
	state->printing = (pthread_mutex_t *)allocate_state_memory((void **) \
				&state->printing, sizeof(pthread_mutex_t));
	state->death = (pthread_mutex_t *)allocate_state_memory((void **) \
				&state->death, sizeof(pthread_mutex_t));
	state->eating = (pthread_mutex_t *)allocate_state_memory((void **) \
				&state->eating, sizeof(pthread_mutex_t));
	if (!state->rules.n_philo || !state->philos || ! state->forks \
	|| !state->printing || !state->death || !init_each_mutex(&state->forks, \
				state->rules.n_philo))
		free_allocated_memory_exit((void **)&state);
	if (!init_mutexes(state))
		free_allocated_memory_exit((void **)&state);
}

void	set_null_values(t_state **state_var)
{
	t_state		*state;

	state = *state_var;
	state->is_finished = false;
	state->syncing = 0;
	state->dead_id = -1;
	state->meals_finished = 0;
	state->philos = NULL;
	state->forks = NULL;
}

