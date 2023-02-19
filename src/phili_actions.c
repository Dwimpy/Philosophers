/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phili_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 15:24:21 by arobu             #+#    #+#             */
/*   Updated: 2023/02/19 21:11:47 by arobu            ###   ########.fr       */
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

	state = (t_state *)philosopher->param;
	rules = &state->rules;
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
	safe_printing(philosopher);
	ft_usleep(rules->time_to_eat);
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
