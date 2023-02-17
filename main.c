/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 18:29:35 by arobu             #+#    #+#             */
/*   Updated: 2023/02/17 19:23:33 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "philosophers.h"
#include "state.h"

int	main(int argc, char **argv)
{
	t_state			state;
	int				i;

	initialize_state(&state, argc, argv);

	i = -1;
	while (++i < 5)
	{
		initialize_philo(&state, i);
	}
	while (1)
	{
		
	}
	return (0);
}