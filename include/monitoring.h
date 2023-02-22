/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 18:46:59 by arobu             #+#    #+#             */
/*   Updated: 2023/02/22 03:55:31 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MONITORING_H
# define MONITORING_H

#include <pthread.h>

typedef struct s_monitoring
{
	void			*param;
	pthread_mutex_t	*mutex;
}				t_monitoring;

#endif
