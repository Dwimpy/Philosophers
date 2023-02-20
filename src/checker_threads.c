/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_threads.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 18:53:32 by arobu             #+#    #+#             */
/*   Updated: 2023/02/20 22:33:31 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/state.h"

static void	dinner_is_over(t_state *state, int32_t id, bool meal, bool death);


void	*check_death(void *param)
{
	t_state		*state;
	int			i;

	state = (t_state *)param;
	state->dt_started = true;
	while (state->are_synced == 0)
		continue ;
	while (!state->dinner_over && !state->is_finished)
	{
		i = -1;
		while (!state->dinner_over && \
				++i < state->rules.number_of_philosophers && \
					!state->is_finished)
		{
			if (time_stamp_ms() - state->philosophers[i].time_of_last_meal >= \
						state->rules.time_to_die)
			{
				pthread_mutex_lock(state->death_mutex);
				state->is_finished = 1;
				print_death(state, i);
				pthread_mutex_unlock(state->death_mutex);
			}
		}
	}
	return (NULL);
}


void	*check_meals(void *param)
{
	t_state		*state;
	int			i;
	bool		all_ate;

	state = (t_state *)param;
	i = -1;
	state->cm_started = true;
	while (state->are_synced == 0)
		continue ;
	while (!state->dinner_over && !state->is_finished)
	{
		i = -1;
		all_ate = true;
		while (!state->dinner_over && !state->is_finished && \
			++i < state->rules.number_of_philosophers)
		{
			if (state->philosophers[i].meals_eaten < \
					state->rules.times_must_eat)
				all_ate = false;
		}
		if (all_ate)
			dinner_is_over(state, -1, true, false);
	}
	return (NULL);
}

void	*sync_threads(void *param)
{
	bool		in_sync;
	int			i;
	t_state		*state;

	state = (t_state *)param;
	in_sync = false;
	pthread_mutex_lock(state->death_mutex);
	while (in_sync == false)
	{
		i = -1;
		in_sync = true;
		while (++i < state->rules.number_of_philosophers)
		{
			if (state->thread_started == 0 || state->dt_started == 0 || \
		state->philosophers[i].thread_started == 0 || state->cm_started == 0)
				in_sync = false;
		}
	}
	i = -1;
	state->start_time = time_stamp_ms();
	while (++i < state->rules.number_of_philosophers)
		state->philosophers[i].time_of_last_meal = state->start_time;
	state->are_synced = 1;
	pthread_mutex_unlock(state->death_mutex);
	return (NULL);
}

static void	dinner_is_over(t_state *state, int32_t id, bool meal, bool death)
{
	if (meal)
	{
		state->dinner_over = 1;
		print_meals(state);
	}
	else if (death)
	{
		state->is_finished = 1;
		print_death(state, id);
	}
	pthread_mutex_unlock(state->death_mutex);

}
