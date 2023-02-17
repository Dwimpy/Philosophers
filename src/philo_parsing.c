/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 14:08:12 by arobu             #+#    #+#             */
/*   Updated: 2023/02/17 14:34:43 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/state.h"

static void	args_checker(int argc);

void	parse_args(int argc, char **argv)
{
	args_checker(argc);
}

static void	args_checker(int argc)
{
	if (argc != 5 && argc != 6)
	{
		print_error("Incorrect arguments");
		print_usage();
	}
}