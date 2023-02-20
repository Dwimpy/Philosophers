/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:59:38 by arobu             #+#    #+#             */
/*   Updated: 2023/02/20 22:39:14 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STATE_H
# define STATE_H
# include "philosophers.h"
# include <sys/time.h>
# include <stdlib.h>
# include <errno.h>
# include <string.h>

typedef struct timeval	t_time;
typedef struct s_rules	t_rules;
typedef t_rules			(*t_init_rules)(char **argv);

typedef struct s_rules
{
	int32_t			number_of_philosophers;
	int32_t			time_to_die;
	int32_t			time_to_eat;
	int32_t			time_to_sleep;
	int32_t			times_must_eat;
}					t_rules;

typedef struct s_state
{
	long int		start_time;
	t_philosopher	*philosophers;
	t_fork			*forks;
	t_rules			rules;
	t_init_rules	init_rules;
	pthread_t		sync_thread;
	pthread_t		check_death_thread;
	pthread_t		check_meals_thread;
	pthread_mutex_t	*writing;
	pthread_mutex_t	*death_mutex;
	bool			thread_started;
	bool			are_synced;
	bool			dinner_over;
	bool			is_finished;
	bool			dt_started;
	bool			cm_started;
}					t_state;

void		state_initializer_utils(t_state **state, int argc, char **argv);
void		initialize_state(t_state **the_state, int argc, char **argv);
void		init_state_values(t_state *state);
void		initialize_philo(t_state *state);
void		initialize_rules(t_state *state, int argc);
void		rules_checker(t_rules rules, int argc, bool *are_valid);
void		*sync_threads(void *param);
void		*check_death(void *param);
void		*check_meals(void *param);
void		*philosopher_loop(void *param);
long int	time_stamp_ms(void);
void		ft_usleep(long int time_ms);
void		print_death(t_state	*state, int id);
void		print_meals(t_state	*state);
int			ft_atoi(const char *s);
void		print_error(char *error);
void		print_usage(void);
void		print_and_exit(t_state *state);
void		state_exit_error(t_state *state);

#endif
