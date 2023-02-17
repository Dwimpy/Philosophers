/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_initializer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 14:18:30 by arobu             #+#    #+#             */
/*   Updated: 2023/02/17 20:01:02 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/state.h"

static t_rules	initialize_no_optional(char **argv);
static t_rules	initialize_optional(char **argv);
static void		initialize_rules(t_state *state, int argc);

void	initialize_state(t_state *state, int argc, char **argv)
{
	initialize_rules(state, argc);
	state->rules = state->init_rules(argv);
	state->philosophers = (t_philosopher *)malloc(sizeof(t_philosopher) * \
									state->rules.number_of_philosophers);
	state->forks = (t_fork *)malloc(sizeof(t_fork) * \
									state->rules.number_of_philosophers);
	pthread_mutex_init(&state->writing, NULL);
}

static void	initialize_rules(t_state *state, int argc)
{
	if (argc == 5)
		state->init_rules = &initialize_no_optional;
	else if (argc == 6)
		state->init_rules = &initialize_optional;
	else
	{
		print_error("Incorrect arguments");
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

// number_of_philosophers time_to_die time_to_eat time_to_sleep
// [number_of_times_each_philosopher_must_eat]