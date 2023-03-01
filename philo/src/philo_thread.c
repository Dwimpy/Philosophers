/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 01:04:56 by arobu             #+#    #+#             */
/*   Updated: 2023/02/28 18:08:15 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/state.h"

void	*philosophers(void *param)
{
	t_state	*state;
	t_philo	*philo;

	philo = (t_philo *)param;
	state = ((t_state *)philo->param);
	if (philo->id & 1)
		ft_sleep_ms(0.5 * state->rules.time_to_eat);
	while (!state->is_finished && philo->meals != state->rules.times_must_eat)
		philo->action_func(philo);
	if (philo->action == EAT)
	{
		pthread_mutex_unlock(philo->mtx.left);
		pthread_mutex_unlock(philo->mtx.right);
	}
	return (NULL);
}

void	init_philo(t_philo *philo, t_state *state)
{
	philo->mtx.left = &state->forks[philo->id];
	if (state->rules.n_philo != 1)
		philo->mtx.right = &state->forks[(philo->id + 1) % \
		((t_state *)philo->param)->rules.n_philo];
	philo->action = THINK;
	philo->action_func = &philo_think;
	philo->meals = 0;
	philo->threading.start_time = get_time_ms();
}
