/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 19:47:39 by arobu             #+#    #+#             */
/*   Updated: 2023/02/28 15:33:28 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/state.h"

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
	free_memory(state->philos);
	free_memory(state->forks);
	free_memory(state->printing);
	free_memory(state->death);
	free_memory(state->eating);
	free_memory(state);
	if (flag == EXIT_FAILURE)
		exit(EXIT_FAILURE);
}

void	free_memory(void *ptr)
{
	if (ptr)
	{
		free(ptr);
		ptr = NULL;
	}
}
