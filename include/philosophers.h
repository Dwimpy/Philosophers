/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:14:33 by arobu             #+#    #+#             */
/*   Updated: 2023/02/17 20:04:04 by arobu            ###   ########.fr       */
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

typedef enum s_action
{
	THINKING,
	EATING,
	SLEEPING,
	DEAD
}						t_action;

typedef struct s_fork
{
	uint32_t			id;
	t_philosopher		*owner;
	pthread_mutex_t		mutex;
}						t_fork;

typedef struct s_philosopher
{
	uint32_t			id;
	pthread_t			thread;
	t_fork				*left_fork;
	t_fork				*right_fork;
	uint32_t			time_of_last_meal;
	t_action			state;
	void				*param;
}						t_philosopher;

void	safe_printing(t_philosopher *philosopher, pthread_mutex_t *writing);
void	action_time_ms(t_philosopher *philosopher, \
							uint32_t time_to_sleep);
#endif
