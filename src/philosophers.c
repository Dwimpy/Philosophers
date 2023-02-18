/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:37:13 by arobu             #+#    #+#             */
/*   Updated: 2023/02/18 23:46:21 by arobu            ###   ########.fr       */
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
	while (1)
	{
		philosopher->action(philosopher);
	}
	return (NULL);
}

void	initialize_philo(t_state *state, uint32_t id)
{
	t_philosopher	*philosopher;

	philosopher = &state->philosophers[id];
	philosopher->id = id;
	philosopher->state = TAKING_FORK;
	philosopher->action = &philosopher_think;
	philosopher->left_fork = NULL;
	philosopher->right_fork = NULL;
	philosopher->param = (t_state *)state;
	pthread_create(&philosopher->thread, NULL, \
					philosopher_loop, &state->philosophers[id]);
}