/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 20:16:17 by arobu             #+#    #+#             */
/*   Updated: 2023/02/15 21:08:34 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_philosopher	*philosophers;
	int				i;

	philosophers = malloc(sizeof(t_philosopher) * 5);
	i = -1;
	while (++i < 5)
	{
		philosophers[i].id = i;
		philosophers[i].msg_queue = msg_queue_init();
	}
	send_message(RELEASE, &philosophers[0], &philosophers[1]);
	printf("Request sent: %d\n", philosophers[1].msg_queue->front->type);
	return (0);
}
