/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:37:13 by arobu             #+#    #+#             */
/*   Updated: 2023/02/21 00:05:56 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/state.h"

void	*philosopher_loop(void *param)
{
	t_philosopher		*philosopher;
	t_state				*state;
	t_rules				*rules;

	philosopher = (t_philosopher *)param;
	state = (t_state *)philosopher->param;
	rules = &state->rules;
	sync_philosophers(philosopher, rules->time_to_eat);
	while (!state->dinner_over && !state->is_finished)
		philosopher->action(philosopher);
	if (philosopher->state == EATING && rules->number_of_philosophers > 1)
	{
		pthread_mutex_unlock(&philosopher->left->mutex);
		pthread_mutex_unlock(&philosopher->right->mutex);
	}
	return (NULL);
}

void	initialize_philo(t_state *state)
{
	t_philosopher	*philosopher;
	int				i;

	i = -1;
	philosopher = state->philosophers;
	while (++i < state->rules.number_of_philosophers)
	{
		philosopher[i].id = i;
		philosopher[i].state = THINKING;
		philosopher[i].action = &philosopher_think;
		philosopher[i].left = &state->forks[i];
		philosopher[i].right = &state->forks[(i + 1) % \
							state->rules.number_of_philosophers];
		philosopher[i].time_of_last_meal = state->start_time;
		philosopher[i].thread_started = 0;
		philosopher[i].meals_eaten = 0;
		philosopher[i].thread_ended = 0;
		philosopher[i].param = (t_state *)state;
		pthread_create(&philosopher[i].thread, NULL, \
						philosopher_loop, &philosopher[i]);
	}
	if (state->rules.number_of_philosophers == 1)
		pthread_detach(philosopher[0].thread);
}

void	sync_philosophers(t_philosopher *philosopher, int32_t time_to_eat)
{
	t_state		*state;

	state = (t_state *)philosopher->param;
	philosopher->thread_started = true;
	while (state->are_synced == false)
		continue ;
	if ((philosopher->id & 1) == 0x1)
		ft_usleep(0.5 * time_to_eat);
}
