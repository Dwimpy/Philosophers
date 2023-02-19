/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_forks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 21:10:00 by arobu             #+#    #+#             */
/*   Updated: 2023/02/19 21:10:45 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	lock_forks(t_philosopher *philosopher)
{
	pthread_mutex_lock(&philosopher->left->mutex);
	pthread_mutex_lock(&philosopher->right->mutex);
}

void	unlock_forks(t_philosopher *philosopher)
{
	pthread_mutex_unlock(&philosopher->left->mutex);
	pthread_mutex_unlock(&philosopher->right->mutex);
}
