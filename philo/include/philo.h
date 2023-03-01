/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 17:08:02 by arobu             #+#    #+#             */
/*   Updated: 2023/02/27 21:31:07 by arobu            ###   ########.fr       */
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
	SLEEP
}					t_action;

typedef struct s_mutexes
{
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
}					t_mutexes;

typedef struct s_threading
{
	pthread_t		thread;
	uint64_t		start_time;
}					t_threading;

typedef struct s_philo
{
	uint32_t		id;
	t_threading		threading;
	t_action		action;
	t_philo_action	action_func;
	t_mutexes		mtx;
	int32_t			meals;
	uint64_t		last_meal;
	void			*param;
}					t_philo;

uint64_t	get_time_diff_ms(uint64_t start);
uint64_t	get_time_ms(void);
void		ft_sleep_ms(uint64_t time);
void		*philosophers(void *param);
void		philo_think(t_philo *philo);
void		philo_hungry(t_philo *philo);
void		philo_eat(t_philo *philo);
void		philo_sleep(t_philo *philo);
void		get_forks(t_philo *philo);
void		release_forks(t_philo *philo);
void		*death_monitor(void *param);
void		*meal_monitor(void *param);
void		philo_print_think(t_philo *philo);
void		philo_print_hungry(t_philo *philo);
void		philo_print_eat(t_philo *philo);
void		philo_print_sleep(t_philo *philo);
#endif
