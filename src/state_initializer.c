/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_initializer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 14:18:30 by arobu             #+#    #+#             */
/*   Updated: 2023/02/20 22:25:31 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/state.h"

static t_rules	initialize_no_optional(char **argv);
static t_rules	initialize_optional(char **argv);
void			*sync_threads(void *param);

void	initialize_state(t_state **the_state, int argc, char **argv)
{
	t_state	*state;

	*the_state = (t_state *)malloc(sizeof(t_state));
	if (!(*the_state))
		state_exit_error(*the_state);
	state = *the_state;
	state->philosophers = NULL;
	state->forks = NULL;
	state->writing = NULL;
	state->death_mutex = NULL;
	state_initializer_utils(&state, argc, argv);
	pthread_mutex_init(state->writing, NULL);
	pthread_mutex_init(state->death_mutex, NULL);
	pthread_mutex_lock(state->death_mutex);
	init_state_values(state);
}

void	initialize_rules(t_state *state, int argc)
{
	if (argc == 5)
		state->init_rules = &initialize_no_optional;
	else if (argc == 6)
		state->init_rules = &initialize_optional;
	else
	{
		print_error("Incorrect arguments");
		print_usage();
		exit(1);
	}
	return ;
}

static t_rules	initialize_no_optional(char **argv)
{
	t_rules	rules;

	rules.number_of_philosophers = ft_atoi(argv[1]);
	rules.time_to_die = ft_atoi(argv[2]);
	rules.time_to_eat = ft_atoi(argv[3]);
	rules.time_to_sleep = ft_atoi(argv[4]);
	rules.times_must_eat = -1;
	return (rules);
}

static t_rules	initialize_optional(char **argv)
{
	t_rules	rules;

	rules.number_of_philosophers = ft_atoi(argv[1]);
	rules.time_to_die = ft_atoi(argv[2]);
	rules.time_to_eat = ft_atoi(argv[3]);
	rules.time_to_sleep = ft_atoi(argv[4]);
	rules.times_must_eat = ft_atoi(argv[5]);
	return (rules);
}

void	rules_checker(t_rules rules, int argc, bool *are_valid)
{
	if (rules.number_of_philosophers < 1)
	{
		print_error("Number of philosophers must be at least 1");
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
