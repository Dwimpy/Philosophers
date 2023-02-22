/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 19:29:52 by arobu             #+#    #+#             */
/*   Updated: 2023/02/22 05:31:31 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/state.h"

static void	set_valid_args(t_rules rules, int argc, bool *are_valid);

void	check_args(int argc, char **argv)
{
	char		*str;
	size_t		i;
	size_t		j;

	str = NULL;
	i = 0;
	j = -1;
	if (argc < 5 || argc > 6)
		print_usage_and_exit();
	while (++i < (size_t) argc)
	{
		j = -1;
		str = ft_strtrim(argv[i], " ");
		while (++j < ft_strlen(argv[i]))
		{
			if (!ft_isdigit(str[j]))
			{
				print_error("Wrong argument type");
				free(str);
				exit(1);
			}
		}
		free(str);
	}
}

bool	check_rules(t_rules rules, int argc)
{
	bool		are_valid;

	are_valid = true;
	set_valid_args(rules, argc, &are_valid);
	return (are_valid);
}

static void	set_valid_args(t_rules rules, int argc, bool *are_valid)
{
	if (rules.n_philo < 1 || rules.n_philo > 200)
	{
		print_error("Number of philosophers must be be between 1 and 200");
		*are_valid = false;
	}
	if (rules.time_to_die < 0)
	{
		print_error("Time to die must be at least 0ms");
		*are_valid = false;
	}
	if (rules.time_to_eat < 60)
	{
		print_error("Time to eat must be at least 60ms");
		*are_valid = false;
	}
	if (rules.time_to_sleep < 60)
	{
		print_error("Time to sleep must be at least 60ms");
		*are_valid = false;
	}
	if (argc == 6 && rules.times_must_eat == 0)
	{
		print_error("Times must eat must be at least 1");
		*are_valid = false;
	}
}
