/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_functions.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 19:19:21 by arobu             #+#    #+#             */
/*   Updated: 2023/02/22 03:51:04 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_FUNCTIONS_H
# define UTIL_FUNCTIONS_H

# include <stdlib.h>
# include <unistd.h>

int			ft_isdigit(int c);
int			ft_atoi(const char *s);
size_t		ft_strlen(const char *s);
char		*ft_strdup(const char *string);
char		*ft_strtrim(const char *s1, const char *set);
char		*ft_substr(char const *str, unsigned int start_index, size_t len);

#endif
