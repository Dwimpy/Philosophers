/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 01:04:56 by arobu             #+#    #+#             */
/*   Updated: 2023/02/22 15:37:28 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/state.h"

static void	init_philo(t_philo *philo, t_state *state);

void	*philosophers(void *param)
{
	t_state	*state;
	t_philo	*philo;

	philo = (t_philo *)param;
	state = ((t_state *)philo->param);
	while (state->syncing == 0)
		continue ;
	init_philo(philo, state);
	if (philo->id & 1)
		ft_sleep_ms(0.5 * state->rules.time_to_eat);
	while (!state->is_finished)
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
	philo->mtx.right = &state->forks[(philo->id + 1) % \
		((t_state *)philo->param)->rules.n_philo];
	philo->action = THINK;
	philo->action_func = &philo_think;
	philo->threading.start_time = get_time_ms();
}
