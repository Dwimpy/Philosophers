/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ticket.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 22:36:16 by arobu             #+#    #+#             */
/*   Updated: 2023/02/18 22:54:55 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TICKET_H
# define TICKET_H

# include <pthread.h>

typedef struct s_ticket	t_ticket;

typedef struct s_ticket
{
	unsigned int	number;
	t_ticket		*next;
}				t_ticket;

typedef struct s_ticket_queue
{
	t_ticket		*front;
	t_ticket		*rear;
	unsigned int	size;
	pthread_mutex_t	mutex;
}				t_ticket_queue;

t_ticket_queue	*create_queue(void);
t_ticket		*create_ticket(unsigned int number);
void			enqueue(t_ticket_queue *queue, t_ticket *ticket);
void			dequeue(t_ticket_queue *queue);

#endif