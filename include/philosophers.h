/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:14:33 by arobu             #+#    #+#             */
/*   Updated: 2023/02/14 20:24:28 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

typedef struct s_philosopher
{
	int				id;
	int				alive;
	int				eating;
	int				ate;
	int				ate_times;
	int				left_fork;
	int				right_fork;
	int				*forks;
	pthread_t		*thread;
	pthread_mutex_t	*mutex;	
}				t_philosopher;

#endif
