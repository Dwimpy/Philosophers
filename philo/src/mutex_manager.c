/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 01:25:12 by arobu             #+#    #+#             */
/*   Updated: 2023/02/22 04:38:00 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/state.h"

bool	init_each_mutex(pthread_mutex_t **forks, int32_t nelem)
{
	int32_t			i;
	int32_t			j;
	pthread_mutex_t	*fork;
	bool			success;

	i = 0;
	j = 0;
	success = true;
	fork = *forks;
	while (i < nelem)
	{
		if (pthread_mutex_init(&fork[i], NULL) != 0)
		{
			while (j < i)
			{
				pthread_mutex_destroy(&fork[j]);
				j++;
			}
			success = false;
			break ;
		}
		i++;
	}
	return (success);
}

bool	init_mutex(pthread_mutex_t *mutex)
{
	if (pthread_mutex_init(mutex, NULL) != 0)
		return (false);
	return (true);
}

bool	init_mutexes(t_state *state)
{
	if (!init_mutex(state->printing))
		return (false);
	if (!init_mutex(state->eating))
	{
		pthread_mutex_destroy(state->printing);
		return (false);
	}
	if (!init_mutex(state->death))
	{
		pthread_mutex_destroy(state->printing);
		pthread_mutex_destroy(state->eating);
		return (false);
	}
	return (true);
}
