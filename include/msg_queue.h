/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg_queue.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 17:12:03 by arobu             #+#    #+#             */
/*   Updated: 2023/02/15 19:54:05 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSG_QUEUE_H
# define MSG_QUEUE_H
# include <stdint.h>
# include "message.h"

typedef struct s_msg_queue	t_msg_queue;

typedef struct s_msg_queue
{
	t_message		*front;
	t_message		*last;
	uint32_t		size;
}					t_msg_queue;

t_msg_queue			*msg_queue_init(void);
void				msg_queue_push(t_msg_queue *queue, t_message *message);
void				msg_queue_pop(t_msg_queue *queue);
void				msg_queue_destroy(t_msg_queue *queue);

#endif