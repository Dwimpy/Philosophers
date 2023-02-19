/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_initializer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 14:18:30 by arobu             #+#    #+#             */
/*   Updated: 2023/02/19 22:08:46 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/state.h"

static t_rules	initialize_no_optional(char **argv);
static t_rules	initialize_optional(char **argv);
void			*sync_threads(void *param);

void	initialize_state(t_state **the_state, int argc, char **argv)
{
	t_state	*state;
	int		i;

	i = -1;
	*the_state = (t_state *)malloc(sizeof(t_state));
	if (!(*the_state))
		state_exit_error(*the_state);
	state = *the_state;
	state->philosophers = NULL;
	state->forks = NULL;
	state->writing = NULL;
	state_initializer_utils(state, argc, argv);
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

void	*sync_threads(void *param)
{
	bool		in_sync;
	int			i;
	t_state		*state;

	state = (t_state *)param;
	in_sync = false;
	while (in_sync == false)
	{
		i = -1;
		in_sync = true;
		while (++i < state->rules.number_of_philosophers)
		{
			if (state->thread_started == 0 || \
				state->philosophers[i].thread_started == 0)
				in_sync = false;
		}
	}
	i = -1;
	state->start_time = time_stamp_ms();
	while (++i < state->rules.number_of_philosophers)
		state->philosophers[i].time_of_last_meal = state->start_time;
	state->are_synced = 1;
	return (NULL);
}
