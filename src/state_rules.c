/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_rules.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 20:44:54 by arobu             #+#    #+#             */
/*   Updated: 2023/02/22 06:42:44 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/state.h"

t_rules	rules_optional(char **argv)
{
	t_rules		rules;

	rules.n_philo = ft_atoi(argv[1]);
	rules.time_to_die = ft_atoi(argv[2]);
	rules.time_to_eat = ft_atoi(argv[3]);
	rules.time_to_sleep = ft_atoi(argv[4]);
	rules.times_must_eat = ft_atoi(argv[5]);
	return (rules);
}

t_rules	rules_no_opt(char **argv)
{
	t_rules		rules;

	rules.n_philo = ft_atoi(argv[1]);
	rules.time_to_die = ft_atoi(argv[2]);
	rules.time_to_eat = ft_atoi(argv[3]);
	rules.time_to_sleep = ft_atoi(argv[4]);
	rules.times_must_eat = -1;
	return (rules);
}

void	set_init_rules(t_state **state, int argc, char **argv)
{
	if (argc == 5)
		(*state)->init_rules = rules_no_opt;
	if (argc == 6)
		(*state)->init_rules = rules_optional;
	(*state)->rules = (*state)->init_rules(argv);
	if (!check_rules((*state)->rules, argc))
		free_allocated_memory_exit((void **)state);
}
