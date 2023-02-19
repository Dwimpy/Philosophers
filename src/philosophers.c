/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:37:13 by arobu             #+#    #+#             */
/*   Updated: 2023/02/19 17:22:42 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/state.h"

void	*philosopher_loop(void *param)
{
	t_philosopher		*philosopher;
	t_rules				*rules;
	t_state				*state;

	philosopher = (t_philosopher *)param;
	state = (t_state *)philosopher->param;
	rules = &state->rules;

	if (philosopher->id & 1)
		ft_usleep(0.5 * rules->time_to_eat);
	while (1)
	{
		philosopher->action(philosopher);
	}
	return (NULL);
}

void	initialize_philo(t_state *state)
{
	t_philosopher	*philosopher;
	int				i;

	philosopher = state->philosophers;
	i = -1;
	while (++i < state->rules.number_of_philosophers)
	{
		philosopher[i].id = i;
		philosopher[i].state = HUNGRY;
		philosopher[i].action = &get_forks;
		philosopher[i].left = &state->forks[i];
		philosopher[i].right = &state->forks[(i + 1) % \
							state->rules.number_of_philosophers];
		philosopher[i].param = (t_state *)state;
		pthread_create(&philosopher->thread, NULL, \
						philosopher_loop, &philosopher[i]);
	}
	i = -1;
	state->start_time = time_stamp_ms();
	while (++i < state->rules.number_of_philosophers)
	{
		philosopher[i].time_of_last_meal = state->start_time;
	}
	state->sync_threads = 1;
}
