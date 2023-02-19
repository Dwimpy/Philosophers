/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 18:29:35 by arobu             #+#    #+#             */
/*   Updated: 2023/02/19 17:32:47 by arobu            ###   ########.fr       */
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

	state = (t_state *)malloc(sizeof(t_state));
	if (!state)
		return (0);
	state->writing = malloc(sizeof(pthread_mutex_t));
	initialize_state(state, argc, argv);
	i = -1;
	initialize_philo(state);
	while (1)
	{
		i = -1;
		while (++i < state->rules.number_of_philosophers)
		{
			if (time_stamp_ms() - state->philosophers[i].time_of_last_meal >= \
						state->rules.time_to_die)
			{
				print_death(state, i);
				exit(0);
			}
		}
	}
	return (0);
}
