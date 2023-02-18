/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_ticket.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 22:32:09 by arobu             #+#    #+#             */
/*   Updated: 2023/02/18 22:55:27 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/state.h"

t_ticket_queue	*create_queue(void)
{
	t_ticket_queue	*queue;

	queue = (t_ticket_queue *)malloc(sizeof(t_ticket_queue));
	if (!queue)
		return (NULL);
	queue->front = NULL;
	queue->rear = NULL;
	queue->size = 0;
	pthread_mutex_init(&queue->mutex, NULL);
	return (queue);
}

t_ticket	*create_ticket(unsigned int number)
{
	t_ticket	*ticket;

	ticket = (t_ticket *)malloc(sizeof(t_ticket));
	if (!ticket)
		return (NULL);
	ticket->number = number;
	ticket->next = NULL;
	return (ticket);
}

void	enqueue(t_ticket_queue *queue, t_ticket *ticket)
{
	pthread_mutex_lock(&queue->mutex);
	if (queue->rear == NULL)
	{
		queue->front = ticket;
		queue->rear = ticket;
	}
	else
	{
		queue->rear->next = ticket;
		queue->rear = ticket;
	}
	queue->size++;
	pthread_mutex_unlock(&queue->mutex);
}

void	dequeue(t_ticket_queue *queue)
{
	t_ticket	*temp;

	pthread_mutex_lock(&queue->mutex);
	if (queue->front == NULL)
		return ;
	temp = queue->front;
	queue->front = queue->front->next;
	if (queue->front == NULL)
		queue->rear = NULL;
	free(temp);
	queue->size--;
	pthread_mutex_unlock(&queue->mutex);
}

