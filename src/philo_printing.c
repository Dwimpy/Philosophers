/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_printing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 00:41:34 by arobu             #+#    #+#             */
/*   Updated: 2023/02/22 15:29:03 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/state.h"

void	philo_print_think(t_philo *philo)
{
	if (((t_state *)philo->param)->is_finished)
		return ;
	pthread_mutex_lock(((t_state *)philo->param)->printing);
	printf("%llu %d is thinking\n", get_time_ms() - \
		((t_state *)philo->param)->start_time, philo->id);
	pthread_mutex_unlock(((t_state *)philo->param)->printing);
}

void	philo_print_hungry(t_philo *philo)
{
	if (((t_state *)philo->param)->is_finished)
		return ;
	pthread_mutex_lock(((t_state *)philo->param)->printing);
	printf("%llu %d has taken a fork\n", get_time_ms() - \
		((t_state *)philo->param)->start_time, philo->id);
	pthread_mutex_unlock(((t_state *)philo->param)->printing);
}

void	philo_print_eat(t_philo *philo)
{
	if (((t_state *)philo->param)->is_finished)
		return ;
	pthread_mutex_lock(((t_state *)philo->param)->printing);
	printf("%llu %d is eating\n", get_time_ms() - \
		((t_state *)philo->param)->start_time, philo->id);
	pthread_mutex_unlock(((t_state *)philo->param)->printing);
}

void	philo_print_sleep(t_philo *philo)
{
	if (((t_state *)philo->param)->is_finished)
		return ;
	pthread_mutex_lock(((t_state *)philo->param)->printing);
	printf("%llu %d is sleeping\n", get_time_ms() - \
		((t_state *)philo->param)->start_time, philo->id);
	pthread_mutex_unlock(((t_state *)philo->param)->printing);
}
