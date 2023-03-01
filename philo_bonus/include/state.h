/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 18:51:26 by arobu             #+#    #+#             */
/*   Updated: 2023/02/28 18:27:45 by arobu            ###   ########.fr       */
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
# include <semaphore.h>
# include <pthread.h>
# include <fcntl.h>
# include "util_functions.h"
# include "philo.h"
# define DEATH 0
# define MEAL 1

typedef struct s_rules	t_rules;
typedef t_rules			(*t_init_rules)(char **argv);

typedef struct s_rules
{
	int32_t		n_philo;
	uint64_t	time_to_die;
	uint64_t	time_to_eat;
	uint64_t	time_to_sleep;
	int32_t		times_must_eat;
}				t_rules;

typedef struct s_state
{
	bool			is_finished;
	t_philo			*philos;
	sem_t			*forks;
	sem_t			*printing;
	sem_t			*death;
	uint64_t		start_time;
	int32_t			dead_id;
	int32_t			meals_finished;
	uint64_t		time_of_last_meal;
	uint64_t		time_of_death;
	t_init_rules	init_rules;
	t_rules			rules;
}				t_state;

t_state		*init_state(int argc, char **argv);
void		print_usage_and_exit(void);
void		print_error(char *error);
void		create_processes(t_state *state);
bool		check_rules(t_rules rules, int argc);
void		check_args(int argc, char **argv);
void		set_init_rules(t_state **state, int argc, char **argv);
bool		init_semaphores(t_state *state);
void		set_null_values(t_state **state_var);
void		allocate_state_members(t_state **state_var);
void		*allocate_state_memory(void **ptr, size_t size);
void		*allocate_memory_nelem(void **ptr, size_t size, size_t nelem);
void		free_memory(void *ptr);
void		free_allocated_memory_exit(void **ptr, int flag);
void		print_results(t_state *state);
void		destroy_semaphores(t_state *state);
#endif
