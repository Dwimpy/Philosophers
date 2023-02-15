/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 17:25:31 by arobu             #+#    #+#             */
/*   Updated: 2023/02/15 21:07:41 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/message.h"
#include "../include/philosophers.h"
#include <stdio.h>

void	send_message(t_type type, void *sender, void *receiver)
{
	t_message		*message;

	message = malloc(sizeof(t_message));
	if (message == NULL)
		return ;
	message->type = type;
	message->sender = (t_philosopher *)sender;
	message->next = NULL;
	msg_queue_push(((t_philosopher *)receiver)->msg_queue, message);
	printf("Aristotle %d sent a fuck you message to Platon %d\n", ((t_philosopher *)sender)->id, ((t_philosopher *)receiver)->id);
}