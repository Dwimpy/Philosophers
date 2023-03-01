/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 17:08:05 by arobu             #+#    #+#             */
/*   Updated: 2023/02/27 22:45:07 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "../include/state.h"

#include "./include/state.h"

int	main(int argc, char **argv)
{
	t_state			*state;

	state = init_state(argc, argv);
	start_threads(state);
	print_results(state);
	free_allocated_memory_exit((void **)&state, EXIT_SUCCESS);
	return (0);
}
