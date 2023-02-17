/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:49:28 by arobu             #+#    #+#             */
/*   Updated: 2023/02/17 20:03:56 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/state.h"

void	safe_printing(t_philosopher *philosopher, pthread_mutex_t *writing)
{
	pthread_mutex_lock(writing);
	if (philosopher->state == THINKING)
		printf("Philosopher %d is thinking\n", philosopher->id);
	if (philosopher->state == EATING)
		printf("Philosopher %d is eating\n", philosopher->id);
	if (philosopher->state == SLEEPING)
		printf("Philosopher %d is sleeping\n", philosopher->id);
	pthread_mutex_unlock(writing);
}

void	print_error(char *error)
{
	printf("\033[0;91mError:\033[0;39m %s\n", error);
}

void	print_usage(void)
{
	printf("Usage: ./philo_one \
[number_of_philosophers] \
[time to die] \
[time to eat] \
[time to sleep] \
[optional: number_of_times_each_philosopher_must_eat]\n");
}
