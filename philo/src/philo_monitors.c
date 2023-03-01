/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_monitors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 03:40:43 by arobu             #+#    #+#             */
/*   Updated: 2023/02/28 18:20:20 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/state.h"

static void	dinner_is_over(t_state *state, int id);

void	*death_monitor(void *param)
{
	t_state			*state;
	t_philo			*philos;
	uint64_t		i;

	philos = (t_philo *)param;
	state = (t_state *)philos->param;
	ft_sleep_ms(0.95 * state->rules.time_to_die);
	while (!state->is_finished)
	{
		i = -1;
		pthread_mutex_lock(state->death);
		while (++i < state->rules.n_philo)
		{
			if (get_time_ms() - state->philos[i].last_meal > \
				state->rules.time_to_die)
			{
				dinner_is_over(state, i);
				return (NULL);
			}
		}
		pthread_mutex_unlock(state->death);
		usleep(100);
	}
	return (NULL);
}

static void	dinner_is_over(t_state *state, int id)
{
	state->time_of_death = get_time_ms() - state->start_time;
	state->is_finished = 1;
	state->dead_id = id;
	pthread_mutex_unlock(state->death);
}

void	print_results(t_state *state)
{
	pthread_mutex_lock(state->printing);
	if (state->dead_id != -1)
		printf("%llu %d died\n", state->time_of_death, state->dead_id);
	printf("\033[0;92mSimulation Complete.\033[0;39m\n");
	pthread_mutex_unlock(state->printing);
}
