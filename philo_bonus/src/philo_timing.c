/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_timing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 21:03:42 by arobu             #+#    #+#             */
/*   Updated: 2023/02/27 16:26:45 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <stdint.h>
#include <stddef.h>
#include <unistd.h>

uint64_t	get_time_ms(void);
uint64_t	get_time_diff_ms(uint64_t start);

void	ft_sleep_ms(uint64_t time)
{
	long int	start;

	start = get_time_ms();
	while (get_time_ms() - start < time)
		usleep(150);
}

uint64_t	get_time_diff_ms(uint64_t start)
{
	return (get_time_ms() - start);
}

uint64_t	get_time_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}
