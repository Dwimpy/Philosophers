/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_ticket_actions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 23:03:37 by arobu             #+#    #+#             */
/*   Updated: 2023/02/18 23:45:22 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/state.h"

void	get_ticket(t_philosopher *philosopher)
{
	t_ticket	*ticket;
	t_state		*state;

	state = (t_state *)philosopher->param;
	ticket = create_ticket(philosopher->id);
	philosopher->ticket = ticket;
	enqueue(state->queue, ticket);
}

void	philosopher_wait(t_philosopher *philosopher)
{
	t_ticket	*ticket;
	t_state		*state;

	state = (t_state *)philosopher->param;
	get_ticket(philosopher);
	ticket = philosopher->ticket;
	while (state->queue->front != ticket)
		usleep(100);

}