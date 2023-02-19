/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phili_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 15:24:21 by arobu             #+#    #+#             */
/*   Updated: 2023/02/19 17:20:33 by arobu            ###   ########.fr       */
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
	t_state		*state;
	t_rules		*rules;
	t_fork		*left;
	t_fork		*right;

	state = (t_state *)philosopher->param;
	rules = &state->rules;
	pthread_mutex_lock(&philosopher->left->mutex);
	pthread_mutex_lock(&philosopher->right->mutex);
	safe_printing(philosopher);
	safe_printing(philosopher);
	philosopher->action = &philosopher_eat;
	philosopher->state = EATING;
}

void	philosopher_eat(t_philosopher *philosopher)
{
	t_rules	*rules;

	rules = &((t_state *)philosopher->param)->rules;
	safe_printing(philosopher);
	action_time_ms(rules->time_to_eat);
	philosopher->time_of_last_meal = time_stamp_ms();
	pthread_mutex_unlock(&philosopher->left->mutex);
	pthread_mutex_unlock(&philosopher->right->mutex);
	philosopher->action = &philosopher_sleep;
	philosopher->state = SLEEPING;

}

void	philosopher_sleep(t_philosopher *philosopher)
{
	t_rules	*rules;

	rules = &((t_state *)philosopher->param)->rules;
	safe_printing(philosopher);
	action_time_ms(rules->time_to_sleep);
	philosopher->action = &philosopher_think;
	philosopher->state = THINKING;
}
