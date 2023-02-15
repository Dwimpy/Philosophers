/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:14:33 by arobu             #+#    #+#             */
/*   Updated: 2023/02/15 21:56:12 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <pthread.h>
# include <stdint.h>
# include <stdbool.h>
# include "msg_queue.h"

typedef struct s_philosopher	t_philosopher;

typedef struct s_fork
{
	uint32_t			id;
	t_philosopher		*owner;
	pthread_mutex_t		mutex;
	bool				is_dirty;
}						t_fork;

typedef struct s_philosopher
{
	uint32_t			id;
	pthread_t			thread;
	t_msg_queue			*msg_queue;
	t_fork				*left_fork;
	t_fork				*right_fork;
	uint32_t			time_of_last_meal;
}						t_philosopher;

#endif
