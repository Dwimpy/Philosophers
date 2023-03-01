/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_initializers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 18:54:07 by arobu             #+#    #+#             */
/*   Updated: 2023/02/28 18:28:22 by arobu            ###   ########.fr       */
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
	if (!state->philos)
		free_allocated_memory_exit((void **)&state, EXIT_FAILURE);
	if (!init_semaphores(state))
		free_allocated_memory_exit((void **)&state, EXIT_FAILURE);
}

void	set_null_values(t_state **state_var)
{
	t_state		*state;

	state = *state_var;
	state->is_finished = false;
	state->dead_id = -1;
	state->meals_finished = 0;
	state->time_of_last_meal = 0;
	state->time_of_death = 0;
	state->philos = NULL;
	state->forks = NULL;
	state->death = NULL;
	state->printing = NULL;
}
