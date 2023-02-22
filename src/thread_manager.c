/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 04:43:46 by arobu             #+#    #+#             */
/*   Updated: 2023/02/22 15:33:32 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/state.h"

static void	start_checker_threads(t_state *state);

void	start_threads(t_state *state)
{
	int				i;

	i = -1;
	while (++i < state->rules.n_philo)
	{
		state->philos[i].id = i;
		state->philos[i].param = (t_state *)state;
		pthread_create(&state->philos[i].threading.thread, NULL, \
			philosophers, &state->philos[i]);
	}
	i = -1;
	state->start_time = get_time_ms();
	while (++i < state->rules.n_philo)
		state->philos[i].last_meal = state->start_time;
	start_checker_threads(state);
	state->syncing = 1;
	i = -1;
	while (++i < state->rules.n_philo)
		pthread_join(state->philos[i].threading.thread, (NULL));
}

static void	start_checker_threads(t_state *state)
{
	pthread_t		death_tracker;
	pthread_t		meal_tracker;

	pthread_create(&death_tracker, NULL, &death_monitor, &state->philos[0]);
	pthread_create(&meal_tracker, NULL, &meal_monitor, &state->philos[0]);
	pthread_detach(death_tracker);
	pthread_detach(meal_tracker);
}
