/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 17:08:05 by arobu             #+#    #+#             */
/*   Updated: 2023/02/27 18:20:42 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "state.h"

int	main(int argc, char **argv)
{
	t_state			*state;
	int				status;
	pid_t			pid;
	int				i;

	i = -1;
	state = init_state(argc, argv);
	create_processes(state);
	while (wait(&status) > 0 && status == 0)
		;
	while (++i < state->rules.n_philo)
		kill(state->philos[i].process.pid, SIGINT);
	free_allocated_memory_exit((void **)&state, EXIT_SUCCESS);
	return (0);
}
