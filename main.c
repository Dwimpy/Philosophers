/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 18:29:35 by arobu             #+#    #+#             */
/*   Updated: 2023/02/21 00:11:46 by arobu            ###   ########.fr       */
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
	i = -1;
	initialize_state(&state, argc, argv);
	initialize_philo(state);
	state->thread_started = 1;
	pthread_mutex_unlock(state->death_mutex);
	finish_and_free_resources(state);
	return (0);
}
