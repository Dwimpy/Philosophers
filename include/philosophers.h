/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:14:33 by arobu             #+#    #+#             */
/*   Updated: 2023/02/19 17:22:21 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <pthread.h>
# include <stdint.h>
# include <stdbool.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_philosopher	t_philosopher;
typedef void					(*t_philo_action)\
								(t_philosopher *philosopher);
typedef enum s_action
{
	THINKING,
	EATING,
	SLEEPING,
	HUNGRY,
	DEAD
}						t_action;

typedef struct s_fork
{
	unsigned int		id;
	pthread_mutex_t		mutex;
}						t_fork;

typedef struct s_philosopher
{
	uint32_t			id;
	pthread_t			thread;
	long int			time_of_last_meal;
	t_action			state;
	t_philo_action		action;
	t_fork				*left;
	t_fork				*right;
	void				*param;
}						t_philosopher;

void		safe_printing(t_philosopher *philosopher);
void		get_forks(t_philosopher *philosopher);
void		philosopher_think(t_philosopher *philosopher);
void		philosopher_sleep(t_philosopher *philosopher);
void		philosopher_eat(t_philosopher *philosopher);
void		action_time_ms(uint32_t time_to_sleep);
#endif
