/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphore_manager.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 01:25:12 by arobu             #+#    #+#             */
/*   Updated: 2023/02/28 18:28:14 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/state.h"

bool	init_semaphores(t_state *state)
{
	sem_unlink("/printing");
	sem_unlink("/forks");
	sem_unlink("/sync");
	state->forks = sem_open("/forks", O_CREAT, S_IRWXU, state->rules.n_philo);
	state->printing = sem_open("/printing", O_CREAT, S_IRWXU, 1);
	if (state->forks == SEM_FAILED || state->printing == SEM_FAILED)
	{
		destroy_semaphores(state);
		return (false);
	}
	return (true);
}

static void	clean_semaphore(sem_t *sem, char *name)
{
	sem_close(sem);
	unlink(name);
}

void	destroy_semaphores(t_state *state)
{
	clean_semaphore(state->forks, "/forks");
	clean_semaphore(state->printing, "/printing");
}
