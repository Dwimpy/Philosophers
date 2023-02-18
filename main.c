/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 18:29:35 by arobu             #+#    #+#             */
/*   Updated: 2023/02/18 23:46:00 by arobu            ###   ########.fr       */
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
	t_state			state;
	int				i;
	long int		time;

	initialize_state(&state, argc, argv);
	i = -1;
	state.start_time = time_stamp_ms();
	while (++i < state.rules.number_of_philosophers)
		initialize_philo(&state, i);
	while (1)
	{
		i = -1;
		while (++i < state.rules.number_of_philosophers)
		{
		update_time(&state);
			if (state.curr_time - state.philosophers[i].time_of_last_meal >= \
						state.rules.time_to_die)
			{
				state.philosophers[i].state = DEAD;
			}
			if (state.philosophers[i].state == DEAD)
			{
				print_death(&state, i);
				exit(0);
			}
		}
	}
	return (0);
}