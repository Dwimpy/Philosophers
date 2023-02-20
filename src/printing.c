/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:49:28 by arobu             #+#    #+#             */
/*   Updated: 2023/02/20 21:28:24 by arobu            ###   ########.fr       */
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
	if (((t_state *)philosopher->param)->dinner_over == 1 || \
		((t_state *)philosopher->param)->is_finished == 1)
		return ;
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
	pthread_mutex_unlock(state->writing);
}

void	print_error(char *error)
{
	printf("\033[0;91mError:\033[0;39m %s\n", error);
}

void	print_usage(void)
{
	printf("Usage: ./philo \
[number_of_philosophers] \
[time to die] \
[time to eat] \
[time to sleep] \
[optional: number_of_times_each_philosopher_must_eat]\n");
}
