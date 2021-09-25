/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selbert <selbert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 14:19:13 by selbert           #+#    #+#             */
/*   Updated: 2021/09/25 14:19:14 by selbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	size_t	j;
	char	*s2;

	i = ft_strlen(s1);
	j = 0;
	s2 = malloc(sizeof(char) * (i + 1));
	if (!(s2))
		return (NULL);
	while (j < i)
	{
		s2[j] = s1[j];
		j++;
	}
	s2[j] = '\0';
	return (s2);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

size_t	max_len(char const *s, unsigned int start)
{
	size_t	i;

	i = ft_strlen(s) - start ;
	return (i);
}

char	*ft_sub_fill(char const *s, unsigned int start, size_t len, char *sub)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		sub[i] = s[start];
		i++;
		start++;
	}
	sub[i] = '\0';
	return (sub);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	j;

	if (!s)
		return (NULL);
	if (start >= (unsigned int)ft_strlen(s))
		return (ft_strdup(""));
	j = max_len(s, start);
	if (len < j)
	{
		sub = malloc(sizeof(char) * (len + 1));
		if (!(sub))
			return (NULL);
		return (ft_sub_fill(s, start, len, sub));
	}
	else
	{
		sub = malloc(sizeof(char) * (j + 1));
		if (!(sub))
			return (NULL);
		return (ft_sub_fill(s, start, j, sub));
	}
}
