/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_printing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 20:57:56 by arobu             #+#    #+#             */
/*   Updated: 2023/02/20 22:38:57 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/state.h"

void	print_and_exit(t_state *state)
{
	print_usage();
	free(state);
	exit (1);
}

void	print_meals(t_state *state)
{
	int	i;

	i = -1;
	pthread_mutex_lock(state->writing);
	while (++i < state->rules.number_of_philosophers)
		printf("Philosopher %d ate %d times\n", i, \
				state->philosophers[i].meals_eaten);
	pthread_mutex_unlock(state->writing);

}
