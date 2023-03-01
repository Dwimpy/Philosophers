/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 01:04:56 by arobu             #+#    #+#             */
/*   Updated: 2023/02/28 18:29:57 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/state.h"
#include <signal.h>

static void	start_threads(t_philo *philo);

int	philosophers(void *param)
{
	t_state	*state;
	t_philo	*philo;

	philo = (t_philo *)param;
	state = ((t_state *)philo->param);
	pthread_mutex_init(&philo->death, NULL);
	start_threads(philo);
	if (philo->id & 1)
		ft_sleep_ms(0.5 * state->rules.time_to_eat);
	while (!state->is_finished)
		philo->action_func(philo);
	return (0);
}

static void	start_threads(t_philo *philo)
{
	pthread_create(&philo->process.death_thread, NULL, death_monitor, philo);
	pthread_detach(philo->process.death_thread);
}

void	init_philo(t_philo *philo, int id)
{
	t_state	*state;

	state = ((t_state *)philo->param);
	philo->id = id;
	philo->last_meal = ((t_state *)philo->param)->start_time;
	philo->action = THINK;
	philo->action_func = &philo_think;
}
