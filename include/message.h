/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 17:12:34 by arobu             #+#    #+#             */
/*   Updated: 2023/02/15 21:07:51 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESSAGE_H
# define MESSAGE_H
# include <stdlib.h>
# include "message.h"

typedef struct s_message		t_message;

typedef enum s_type
{
	REQUEST,
	RELEASE
}				t_type;

typedef struct s_message
{
	t_type				type;
	void				*sender;
	t_message			*next;	
}						t_message;

void	send_message(t_type type, void *sender, void *receiver);

#endif