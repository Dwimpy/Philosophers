/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg_queue.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 19:25:46 by arobu             #+#    #+#             */
/*   Updated: 2023/02/15 19:54:20 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/msg_queue.h"

t_msg_queue	*msg_queue_init(void)
{
	t_msg_queue		*msg_queue;

	msg_queue = malloc(sizeof(t_msg_queue));
	if (msg_queue == NULL)
		return (NULL);
	msg_queue->front = NULL;
	msg_queue->last = NULL;
	msg_queue->size = 0;
	return (msg_queue);
}

void	msg_queue_push(t_msg_queue *queue, t_message *message)
{
	if (queue->front == NULL)
	{
		queue->front = message;
		queue->last = message;
	}
	else
	{
		queue->last->next = message;
		queue->last = queue->last->next;
	}
	queue->size++;
}

void	msg_queue_pop(t_msg_queue *queue)
{
	t_message	*tmp;

	if (queue->front == NULL)
		return ;
	tmp = queue->front;
	queue->front = queue->front->next;
	free(tmp);
	tmp = NULL;
}

void	msg_queue_destroy(t_msg_queue *queue)
{
	if (!queue)
		return ;
	while (queue->front != NULL)
		msg_queue_pop(queue);
	free(queue);
	queue = NULL;
}