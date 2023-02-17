/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:37:13 by arobu             #+#    #+#             */
/*   Updated: 2023/02/17 20:11:50 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/state.h"

static void	philosopher_eat(t_philosopher *philosopher);
static void	philosopher_think(t_philosopher *philosopher);
static void	philosopher_sleep(t_philosopher *philosopher);

void	*philosopher_loop(void *param)
{
	t_philosopher		*philosopher;
	t_rules				*rules;
	t_state				*state;

	philosopher = (t_philosopher *)param;
	state = (t_state *)philosopher->param;
	rules = &((t_state *)philosopher->param)->rules;
	while (1)
	{
		philosopher_think(philosopher);
		philosopher_eat(philosopher);
		philosopher_sleep(philosopher);
	}
	return (NULL);
}

static void	philosopher_think(t_philosopher *philosopher)
{
	safe_printing(philosopher, &((t_state *)philosopher->param)->writing);
	philosopher->state = EATING;
}

static void	philosopher_sleep(t_philosopher *philosopher)
{
	t_rules	*rules;

	rules = &((t_state *)philosopher->param)->rules;
	safe_printing(philosopher, &((t_state *)philosopher->param)->writing);
	action_time_ms(philosopher, rules->time_to_sleep);
	philosopher->state = THINKING;
}

static void	philosopher_eat(t_philosopher *philosopher)
{
	t_rules	*rules;

	rules = &((t_state *)philosopher->param)->rules;
	safe_printing(philosopher, &((t_state *)philosopher->param)->writing);
	action_time_ms(philosopher, rules->time_to_eat);
	philosopher->state = SLEEPING;
}

void	initialize_philo(t_state *state, uint32_t id)
{
	t_philosopher	*philosopher;

	philosopher = &state->philosophers[id];
	philosopher->id = id;
	philosopher->state = THINKING;
	philosopher->left_fork = NULL;
	philosopher->right_fork = NULL;
	philosopher->time_of_last_meal = 0;
	philosopher->param = (t_state *)state;
	pthread_create(&philosopher->thread, NULL, \
					philosopher_loop, &state->philosophers[id]);
}