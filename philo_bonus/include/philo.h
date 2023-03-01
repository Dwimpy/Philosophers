/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 17:08:02 by arobu             #+#    #+#             */
/*   Updated: 2023/02/28 17:33:09 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <stdint.h>

typedef struct s_philo	t_philo;
typedef void			(*t_philo_action)(t_philo *philo);

typedef enum s_action
{
	THINK,
	HUNGRY,
	EAT,
	SLEEP,
	DEAD
}					t_action;

typedef struct s_process
{
	pid_t			pid;
	pid_t			child_pid;
	pthread_t		death_thread;
	uint64_t		start_time;
}					t_process;

typedef struct s_philo
{
	uint32_t		id;
	t_process		process;
	t_action		action;
	t_philo_action	action_func;
	pthread_mutex_t	death;
	uint64_t		last_meal;
	void			*param;
}					t_philo;

uint64_t	get_time_diff_ms(uint64_t start);
uint64_t	get_time_ms(void);
void		ft_sleep_ms(uint64_t time);
int			philosophers(void *param);
void		philo_think(t_philo *philo);
void		philo_hungry(t_philo *philo);
void		philo_eat(t_philo *philo);
void		philo_sleep(t_philo *philo);
void		get_forks(t_philo *philo);
void		release_forks(t_philo *philo);
void		*death_monitor(void *param);
void		*meal_monitor(void *param);
void		init_philo(t_philo *philo, int id);
void		philo_print_think(t_philo *philo);
void		philo_print_hungry(t_philo *philo);
void		philo_print_eat(t_philo *philo);
void		philo_print_sleep(t_philo *philo);
#endif
