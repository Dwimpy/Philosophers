/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility_functions2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 18:59:37 by arobu             #+#    #+#             */
/*   Updated: 2023/02/21 19:20:30 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include "../include/util_functions.h"

int			ft_isdigit(int c);
static int	ft_isspace3(char c);
static void	exit_error(char *msg);

char	*ft_strdup(const char *string)
{
	char	*destination;
	char	*dst_start;
	int		string_len;

	string_len = ft_strlen(string);
	destination = (char *)malloc(sizeof(char) * (string_len + 1));
	if (!destination)
		return (NULL);
	dst_start = destination;
	while (*string)
	{
		*destination = *string;
		destination++;
		string++;
	}
	*destination = '\0';
	return (dst_start);
}

int	ft_atoi(const char *s)
{
	unsigned int	sum;
	int				sign;

	sum = 0;
	sign = 1;
	while (ft_isspace3(*s))
		s++;
	if (*s == '-')
		sign = -1;
	if (*s == '+' || *s == '-')
		s++;
	while (*s)
	{
		if (ft_isdigit(*s))
			sum = sum * 10 + (*s - '0');
		else
			break ;
		s++;
	}
	if (sum > INT_MAX && sign == 1)
		exit_error("Error: Overflow");
	if (sum > 2147483648 && sign == -1)
		exit_error("Error: Underflow");
	return (sign * sum);
}

int	ft_isdigit(int c)
{
	return ((c >= 48) && (c <= 57));
}

static int	ft_isspace3(char c)
{
	return (c == ' '
		|| c == '\r'
		|| c == '\t'
		|| c == '\n'
		|| c == '\f'
		|| c == '\v');
}

static void	exit_error(char *msg)
{
	printf("%s\n", msg);
	exit(EXIT_FAILURE);
}
