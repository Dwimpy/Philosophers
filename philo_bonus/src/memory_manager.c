/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 19:47:39 by arobu             #+#    #+#             */
/*   Updated: 2023/02/27 16:07:57 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/state.h"

// system("leaks philo > leaks_result && cat leaks_result | grep leaked");

void	*allocate_state_memory(void **ptr, size_t size)
{
	*ptr = malloc(size);
	if (!ptr)
	{
		print_error("malloc failed");
		return (NULL);
	}
	return (*ptr);
}

void	*allocate_memory_nelem(void **ptr, size_t size, size_t nelem)
{
	*ptr = NULL;
	*ptr = malloc(size * nelem);
	if (!*ptr)
	{
		print_error("malloc failed");
		return (NULL);
	}
	return (*ptr);
}

void	free_allocated_memory_exit(void **ptr, int flag)
{
	t_state	*state;

	state = (t_state *)(*ptr);
	destroy_semaphores(state);
	free_memory(state->philos);
	free_memory(state);
	exit(flag);
}

void	free_memory(void *ptr)
{
	if (ptr)
	{
		free(ptr);
		ptr = NULL;
	}
}
