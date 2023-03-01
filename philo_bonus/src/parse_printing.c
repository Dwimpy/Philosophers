/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_printing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 19:21:42 by arobu             #+#    #+#             */
/*   Updated: 2023/02/23 21:02:16 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/state.h"

void	print_usage_and_exit(void)
{
	print_error("Wrong number of arguments");
	printf("Usage: \
./philo \
[number_of_philosophers] \
[time_to_die] \
[time_to_eat] \
[time_to_sleep] \
[optional -> number_of_times_each_philosopher_must_eat]");
	exit(EXIT_FAILURE);
}

void	print_error(char *error)
{
	printf("\033[0;91mError:\033[0;39m %s\n", error);
}
