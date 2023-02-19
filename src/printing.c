/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:49:28 by arobu             #+#    #+#             */
/*   Updated: 2023/02/19 22:50:54 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/state.h"

static void	print_action(t_philosopher *philosopher);

void	safe_printing(t_philosopher *philosopher)
{
	pthread_mutex_t	*write;

	write = ((t_state *)philosopher->param)->writing;
	pthread_mutex_lock(write);
	print_action(philosopher);
	pthread_mutex_unlock(write);
}

static void	print_action(t_philosopher *philosopher)
{
	if (philosopher->state == THINKING)
		printf("%ld %d is thinking\n", \
		time_stamp_ms() - ((t_state *)\
			philosopher->param)->start_time, philosopher->id);
	if (philosopher->state == EATING)
		printf("%ld %d is eating\n", \
		time_stamp_ms() - ((t_state *) \
			philosopher->param)->start_time, philosopher->id);
	if (philosopher->state == SLEEPING)
		printf("%ld %d is sleeping\n", \
		time_stamp_ms() - ((t_state *) \
			philosopher->param)->start_time, philosopher->id);
	if (philosopher->state == HUNGRY)
		printf("%ld %d has taken a fork\n", \
		time_stamp_ms() - ((t_state *) \
			philosopher->param)->start_time, philosopher->id);
}

void	print_death(t_state	*state, int id)
{
	pthread_mutex_lock(state->writing);
	printf("%ld %d died\n", time_stamp_ms() - state->start_time, id);
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
