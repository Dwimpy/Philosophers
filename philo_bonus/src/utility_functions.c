/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 19:07:45 by arobu             #+#    #+#             */
/*   Updated: 2023/02/21 19:20:23 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "../include/util_functions.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if ((unsigned char)*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == *s)
		return ((char *)s);
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	unsigned int	count;

	count = 0;
	while (*s)
	{
		count++;
		s++;
	}
	return (count);
}

char	*ft_substr(char const *str, unsigned int start_index, size_t len)
{
	char	*substring;
	size_t	size;
	size_t	i;

	i = 0;
	if (!str)
		return (NULL);
	if (ft_strlen(str) < start_index)
		return (ft_strdup(""));
	str += start_index;
	size = ft_strlen(str);
	if (size < len)
		len = size;
	substring = (char *)malloc(sizeof(char) * (len + 1));
	if (!substring)
		return (NULL);
	while (i < len)
	{
		substring[i] = str[i];
		i++;
	}
	substring[i] = '\0';
	return (substring);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*trimmed_str;
	size_t	s1_len;
	size_t	i;

	trimmed_str = NULL;
	if (!s1 || !set)
		return (NULL);
	i = 0;
	s1_len = ft_strlen(s1) - 1;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	if (i == ft_strlen(s1))
	{
		trimmed_str = (char *)malloc(sizeof(char) * 1);
		if (!trimmed_str)
			return (NULL);
		trimmed_str[0] = '\0';
		return (trimmed_str);
	}
	while (s1_len && ft_strchr(set, s1[s1_len]))
		s1_len--;
	trimmed_str = ft_substr(s1, i, s1_len - i + 1);
	return (trimmed_str);
}

char	*ft_strtrim_char(const char *s1, const char c)
{
	char	*trimmed_str;
	size_t	s1_len;
	size_t	i;

	trimmed_str = NULL;
	if (!s1)
		return (NULL);
	i = 0;
	s1_len = ft_strlen(s1) - 1;
	while (s1[i] == c)
		i++;
	if (i == ft_strlen(s1))
	{
		trimmed_str = (char *)malloc(sizeof(char) * 1);
		if (!trimmed_str)
			return (NULL);
		trimmed_str[0] = '\0';
		return (trimmed_str);
	}
	while (s1_len && s1[s1_len] == c)
		s1_len--;
	trimmed_str = ft_substr(s1, i, s1_len - i + 1);
	return (trimmed_str);
}
