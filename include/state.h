/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 18:51:26 by arobu             #+#    #+#             */
/*   Updated: 2023/02/22 07:35:32 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STATE_H
# define STATE_H

# include <stdint.h>
# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <errno.h>
# include <string.h>
# include "../include/util_functions.h"
# include "../include/philo.h"
# include "../include/monitoring.h"
# define DEATH 0
# define MEAL 1

typedef struct s_rules	t_rules;
typedef t_rules			(*t_init_rules)(char **argv);

typedef struct s_rules
{
	int32_t		n_philo;
	int32_t		time_to_die;
	int32_t		time_to_eat;
	int32_t		time_to_sleep;
	int32_t		times_must_eat;
}				t_rules;

typedef struct s_state
{
	bool			is_finished;
	volatile bool	syncing;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*printing;
	pthread_mutex_t	*death;
	pthread_mutex_t	*eating;
	long int		start_time;
	uint32_t		dead_id;
	uint32_t		meals_finished;
	uint64_t		time_of_last_meal;
	uint64_t		time_of_death;
	uint32_t		total_meals;
	t_init_rules	init_rules;
	t_rules			rules;
}				t_state;

t_state		*init_state(int argc, char **argv);
void		print_usage_and_exit(void);
void		print_error(char *error);
void		start_threads(t_state *state);
bool		check_rules(t_rules rules, int argc);
void		check_args(int argc, char **argv);
void		set_init_rules(t_state **state, int argc, char **argv);
bool		init_each_mutex(pthread_mutex_t **forks, int32_t nelem);
bool		init_mutex(pthread_mutex_t *mutex);
bool		init_mutexes(t_state *state);
void		set_null_values(t_state **state_var);
void		allocate_state_members(t_state **state_var);
void		*allocate_state_memory(void **ptr, size_t size);
void		*allocate_memory_nelem(void **ptr, size_t size, size_t nelem);
void		free_memory(void *ptr);
void		free_allocated_memory_exit(void **ptr);
void		print_results(t_state *state);
#endif
