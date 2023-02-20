/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 15:24:21 by arobu             #+#    #+#             */
/*   Updated: 2023/02/20 23:59:03 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/state.h"

void	philosopher_think(t_philosopher *philosopher)
{
	safe_printing(philosopher);
	philosopher->action = &get_forks;
	philosopher->state = HUNGRY;
}

void	get_forks(t_philosopher *philosopher)
{
	lock_forks(philosopher);
	safe_printing(philosopher);
	safe_printing(philosopher);
	philosopher->action = &philosopher_eat;
	philosopher->state = EATING;
}

void	philosopher_eat(t_philosopher *philosopher)
{
	t_rules	*rules;

	rules = &((t_state *)philosopher->param)->rules;
	if (try_action(philosopher) == 0)
		return ;
	safe_printing(philosopher);
	ft_usleep(rules->time_to_eat);
	philosopher->meals_eaten++;
	philosopher->time_of_last_meal = time_stamp_ms();
	unlock_forks(philosopher);
	philosopher->action = &philosopher_sleep;
	philosopher->state = SLEEPING;
}

void	philosopher_sleep(t_philosopher *philosopher)
{
	t_rules	*rules;

	rules = &((t_state *)philosopher->param)->rules;
	safe_printing(philosopher);
	ft_usleep(rules->time_to_sleep);
	philosopher->action = &philosopher_think;
	philosopher->state = THINKING;
}

int	try_action(t_philosopher *philosopher)
{
	t_state	*state;

	state = (t_state *)philosopher->param;
	pthread_mutex_lock(state->death_mutex);
	if (state->dinner_over || state->is_finished)
	{
		pthread_mutex_unlock(&philosopher->right->mutex);
		pthread_mutex_unlock(&philosopher->left->mutex);
		pthread_mutex_unlock(state->death_mutex);
		return (0);
	}
	pthread_mutex_unlock(state->death_mutex);
	return (1);
}
