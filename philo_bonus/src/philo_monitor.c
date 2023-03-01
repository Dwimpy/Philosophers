/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_monitor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 22:09:24 by arobu             #+#    #+#             */
/*   Updated: 2023/02/28 17:37:18 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "state.h"
#include <signal.h>

static void	dinner_is_over(t_state *state, int flag, int id);

void	*death_monitor(void *param)
{
	t_state			*state;
	t_philo			*philo;

	philo = (t_philo *)param;
	state = (t_state *)philo->param;
	while (!state->is_finished)
	{
		pthread_mutex_lock(&philo->death);
		if (get_time_ms() - philo->last_meal > \
			(uint64_t)state->rules.time_to_die)
		{
			sem_wait(state->printing);
			dinner_is_over(state, DEATH, philo->id);
			pthread_mutex_unlock(&philo->death);
			return (NULL);
		}
		pthread_mutex_unlock(&philo->death);
		usleep(100);
	}
	return (NULL);
}

static void	dinner_is_over(t_state *state, int flag, int id)
{
	if (flag == 0)
	{
		state->time_of_death = get_time_ms() - state->start_time;
		state->is_finished = 1;
		printf("%llu %d died", state->time_of_death, id);
		exit(1);
	}
}
