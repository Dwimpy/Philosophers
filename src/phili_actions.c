/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phili_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 15:24:21 by arobu             #+#    #+#             */
/*   Updated: 2023/02/18 23:50:20 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/state.h"

void	philosopher_think(t_philosopher *philosopher)
{
	safe_printing(philosopher);
	philosopher->action = &get_forks;
	philosopher->state = TAKING_FORK;
}

void	get_forks(t_philosopher *philosopher)
{
	t_state		*state;
	t_rules		*rules;
	t_fork		*left;
	t_fork		*right;

	state = (t_state *)philosopher->param;
	rules = &state->rules;
	left = &state->forks[(philosopher->id + \
		rules->number_of_philosophers - 1) % rules->number_of_philosophers];
	right = &state->forks[(philosopher->id + 1) % \
		rules->number_of_philosophers];
	philosopher_wait(philosopher);
	philosopher->left_fork = left;
	philosopher->right_fork = right;
	dequeue(((t_state *) philosopher->param)->queue);
	pthread_mutex_lock(&left->mutex);
	left->owner = philosopher;
	safe_printing(philosopher);
	pthread_mutex_lock(&right->mutex);
	right->owner = philosopher;
	safe_printing(philosopher);
	philosopher->action = &philosopher_eat;
	philosopher->state = EATING;
}

void	philosopher_eat(t_philosopher *philosopher)
{
	t_rules	*rules;
	t_fork	*left_fork;
	t_fork	*right_fork;

	rules = &((t_state *)philosopher->param)->rules;
	left_fork = philosopher->left_fork;
	right_fork = philosopher->right_fork;
	if (left_fork->owner == philosopher && right_fork->owner == philosopher)
	{
		safe_printing(philosopher);
		action_time_ms(philosopher, rules->time_to_eat);
		philosopher->time_of_last_meal = \
			((t_state *) philosopher->param)->curr_time;
		pthread_mutex_unlock(&left_fork->mutex);
		pthread_mutex_unlock(&right_fork->mutex);
		philosopher->action = &philosopher_sleep;
		philosopher->state = SLEEPING;
	}
}

void	philosopher_sleep(t_philosopher *philosopher)
{
	t_rules	*rules;

	rules = &((t_state *)philosopher->param)->rules;
	safe_printing(philosopher);
	action_time_ms(philosopher, rules->time_to_sleep);
	philosopher->action = &philosopher_think;
	philosopher->state = THINKING;
}
