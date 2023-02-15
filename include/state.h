/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:59:38 by arobu             #+#    #+#             */
/*   Updated: 2023/02/15 17:00:24 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STATE_H
# define STATE_H
# include "philosophers.h"

typedef struct s_state
{
	t_philosopher	*philosophers;
	t_fork			*forks;
	uint32_t		number_of_philosophers;
	uint32_t		time_to_die;
	uint32_t		time_to_eat;
	uint32_t		time_to_sleep;
	uint32_t		number_of_times_each_philosopher_must_eat;
}				t_state;

#endif