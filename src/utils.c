/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 17:04:15 by arobu             #+#    #+#             */
/*   Updated: 2023/02/16 17:07:02 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

static int	ft_isdigit(int c);
static int	ft_isspace3(char c);

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
		return (INT_MAX);
	if (sum > 2147483648 && sign == -1)
		return (INT_MAX);
	return (sign * sum);
}

static int	ft_isdigit(int c)
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
