/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 17:23:32 by arobu             #+#    #+#             */
/*   Updated: 2023/02/17 19:46:43 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/state.h"

void	action_time_ms(t_philosopher *philosopher, \
							uint32_t time_to_sleep)
{
	usleep(time_to_sleep * 1000);
}