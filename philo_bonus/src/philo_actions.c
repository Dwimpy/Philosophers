/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 23:31:50 by arobu             #+#    #+#             */
/*   Updated: 2023/02/28 17:36:39 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/state.h"

void	philo_think(t_philo *philo)
{
	philo_print_think(philo);
	if (((t_state *)philo->param)->rules.n_philo == 1)
	{
		ft_sleep_ms(((t_state *)philo->param)->rules.time_to_die);
		sem_wait(((t_state *)philo->param)->printing);
		printf("%llu %d died", get_time_ms() - philo->last_meal, philo->id);
		exit(1);
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
	t_state		*state;

	state = (t_state *)philo->param;
	pthread_mutex_lock(&philo->death);
	philo_print_eat(philo);
	philo->last_meal = get_time_ms();
	ft_sleep_ms(((t_state *)philo->param)->rules.time_to_eat);
	pthread_mutex_unlock(&philo->death);
	((t_state *)philo->param)->meals_finished++;
	release_forks(philo);
	if (state->rules.times_must_eat != -1 && \
		state->meals_finished == state->rules.times_must_eat)
		exit (0);
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
