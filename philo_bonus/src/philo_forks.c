/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_forks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 01:01:04 by arobu             #+#    #+#             */
/*   Updated: 2023/02/22 23:18:57 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/state.h"

void	get_forks(t_philo *philo)
{
	sem_wait(((t_state *)philo->param)->forks);
	sem_wait(((t_state *)philo->param)->forks);
}

void	release_forks(t_philo *philo)
{
	sem_post(((t_state *)philo->param)->forks);
	sem_post(((t_state *)philo->param)->forks);
}
