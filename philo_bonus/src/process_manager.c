/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 04:43:46 by arobu             #+#    #+#             */
/*   Updated: 2023/02/28 18:27:54 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/state.h"

void	create_processes(t_state *state)
{
	int32_t		i;

	i = -1;
	state->start_time = get_time_ms();
	while (++i < state->rules.n_philo)
	{
		state->philos[i].param = (t_state *)state;
		init_philo(&state->philos[i], i);
		state->philos[i].process.pid = fork();
		if (state->philos[i].process.pid == 0)
		{
			philosophers((void *)&state->philos[i]);
			return ;
		}
	}
	return ;
}
