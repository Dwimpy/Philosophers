/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_monitors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 03:40:43 by arobu             #+#    #+#             */
/*   Updated: 2023/02/22 15:34:28 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/state.h"

static void	dinner_is_over(t_state *state, int flag, int id);

void	*death_monitor(void *param)
{
	t_state			*state;
	t_philo			*philos;
	int				i;

	philos = (t_philo *)param;
	state = (t_state *)philos->param;
	while (state->syncing == 0)
		continue ;
	while (!state->is_finished)
	{
		i = -1;
		while (++i < state->rules.n_philo)
		{
			if (get_time_ms() - state->philos[i].last_meal > \
				state->rules.time_to_die)
			{
				dinner_is_over(state, DEATH, state->philos[i].id);
				return (NULL);
			}
			usleep(100);
		}
	}
	return (NULL);
}

void	*meal_monitor(void *param)
{
	t_philo			*philos;
	t_state			*state;
	int32_t			required_meals;
	int				i;
;
	philos = (t_philo *)param;
	state = (t_state *)philos->param;
	required_meals = state->rules.times_must_eat * state->rules.n_philo;
	while (state->syncing == 0)
		continue ;
	while (!state->is_finished)
	{
		if (state->total_meals == required_meals)
		{
			dinner_is_over(state, MEAL, i);
			return (NULL);
		}
	}
	return (NULL);
}

static void	dinner_is_over(t_state *state, int flag, int id)
{
	if (flag == 0)
	{
		pthread_mutex_lock(state->death);
		state->time_of_death = get_time_ms() - state->start_time;
		state->is_finished = 1;
		state->dead_id = id;
		pthread_mutex_unlock(state->death);
	}
	else if (flag == 1)
	{
		pthread_mutex_lock(state->eating);
		state->is_finished = 1;
		state->meals_finished = 1;
		state->time_of_last_meal = get_time_ms() - state->start_time;
		pthread_mutex_unlock(state->eating);
	}
}

void	print_results(t_state *state)
{
	if (state->dead_id != -1)
		printf("%llu %d died\n", state->time_of_death, state->dead_id);
	else if (state->meals_finished == 1)
		printf("%llu All philosophers have eaten %d times\n", \
			state->time_of_last_meal, state->rules.times_must_eat);

}
