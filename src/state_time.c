/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 17:23:32 by arobu             #+#    #+#             */
/*   Updated: 2023/02/19 16:37:23 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/state.h"

void	action_time_ms(uint32_t time_to_sleep)
{
	ft_usleep(time_to_sleep);
	//usleep(time_to_sleep * 1000);
}

long	time_stamp_ms(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	ft_usleep(long int time_ms)
{
	long int	time;

	time = time_stamp_ms();
	while (time_stamp_ms() - time < time_ms)
	{
		usleep(150);
	}
}
