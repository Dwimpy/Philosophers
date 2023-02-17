/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:59:38 by arobu             #+#    #+#             */
/*   Updated: 2023/02/17 20:00:31 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STATE_H
# define STATE_H
# include "philosophers.h"
# include <sys/time.h>
# include <stdlib.h>

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
	t_philosopher	*philosophers;
	t_fork			*forks;
	t_rules			rules;
	t_time			start_time;
	t_init_rules	init_rules;
	pthread_mutex_t	writing;
}					t_state;

void	initialize_state(t_state *state, int argc, char **argv);
void	initialize_philo(t_state *state, uint32_t id);
void	*philosopher_loop(void *param);
int		ft_atoi(const char *s);
void	print_error(char *error);
void	print_usage(void);

#endif