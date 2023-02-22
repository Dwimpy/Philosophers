/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_forks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 01:01:04 by arobu             #+#    #+#             */
/*   Updated: 2023/02/22 01:02:04 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	get_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->mtx.left);
	pthread_mutex_lock(philo->mtx.right);
}

void	release_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->mtx.left);
	pthread_mutex_unlock(philo->mtx.right);
}
