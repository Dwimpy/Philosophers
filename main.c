/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 18:29:35 by arobu             #+#    #+#             */
/*   Updated: 2023/02/19 22:26:00 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "philosophers.h"
#include "state.h"

int	main(int argc, char **argv)
{
	t_state			*state;
	int				i;

	state = NULL;
	initialize_state(&state, argc, argv);
	initialize_philo(state);
	state->thread_started = 1;
	while (state->are_synced == 0)
		continue ;
	while (!state->is_dead && !state->is_finished)
	{
		i = -1;
		while (++i < state->rules.number_of_philosophers)
		{
			if (time_stamp_ms() - state->philosophers[i].time_of_last_meal >= \
						state->rules.time_to_die)
			{
				state->is_dead = 1;
				print_death(state, i);
				exit(0);
			}
		}
	}
	return (0);
}
