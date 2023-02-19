/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 14:08:12 by arobu             #+#    #+#             */
/*   Updated: 2023/02/19 21:04:34 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/state.h"

static void	args_checker(int argc);

void	parse_args(int argc)
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
