/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 23:31:50 by arobu             #+#    #+#             */
/*   Updated: 2023/02/22 15:40:44 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/state.h"

static bool	try_eating(t_philo *philo);

void	philo_think(t_philo *philo)
{
	philo_print_think(philo);
	if (((t_state *)philo->param)->rules.n_philo == 1)
	{
		ft_sleep_ms(1.5 * ((t_state *)philo->param)->rules.time_to_die);
		return ;
	}
	philo->action = HUNGRY;
	philo->action_func = &philo_hungry;
}

void	philo_hungry(t_philo *philo)
{
	get_forks(philo);
	philo_print_hungry(philo);
	philo_print_hungry(philo);
	philo->action = EAT;
	philo->action_func = &philo_eat;
}

void	philo_eat(t_philo *philo)
{
	if (!try_eating(philo))
		return ;
	philo_print_eat(philo);
	pthread_mutex_lock(((t_state *)philo->param)->eating);
	((t_state *)philo->param)->total_meals++;
	pthread_mutex_unlock(((t_state *)philo->param)->eating);
	ft_sleep_ms(((t_state *)philo->param)->rules.time_to_eat);
	philo->last_meal = get_time_ms();
	release_forks(philo);
	philo->action = SLEEP;
	philo->action_func = &philo_sleep;
}

void	philo_sleep(t_philo *philo)
{
	philo_print_sleep(philo);
	ft_sleep_ms(((t_state *)philo->param)->rules.time_to_sleep);
	philo->action = THINK;
	philo->action_func = &philo_think;
}

static bool	try_eating(t_philo *philo)
{
	pthread_mutex_lock(((t_state *)philo->param)->death);
	if (((t_state *)philo->param)->is_finished == 1)
	{
		pthread_mutex_unlock(philo->mtx.left);
		pthread_mutex_unlock(philo->mtx.right);
		pthread_mutex_unlock(((t_state *)philo->param)->death);
		return (false);
	}
	pthread_mutex_unlock(((t_state *)philo->param)->death);
	return (true);
}

