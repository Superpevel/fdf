/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selbert <selbert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 13:27:27 by selbert           #+#    #+#             */
/*   Updated: 2021/09/25 13:29:52 by selbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_char(char c, char *set)
{
	while (*set != '\0')
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

size_t	ft_after(char *s, char *set)
{
	size_t	j;

	s = s + ft_strlen(s) - 1;
	j = 0;
	while (ft_is_char(*s, set))
	{
		s--;
		j++;
	}
	return (j);
}

char	*ft_fills(char *new, size_t i, size_t j, char *s)
{
	size_t	k;
	size_t	size;

	k = 0;
	s = s - i;
	size = ft_strlen(s);
	s = s + i;
	while (i < size - j)
	{
		i++;
		new[k] = *s;
		k++;
		s++;
	}
	new[k] = '\0';
	return (new);
}

char	*ft_strtrim(char *s, char *set)
{
	int		len;
	int		i;
	int		start;
	char	*dest;

	i = 0;
	if (!s)
		return (0);
	if (!set)
		return (ft_strdup(s));
	len = ft_strlen(s);
	while (s[i] && ft_strchr(set, s[i]))
		i++;
	if (s[i] == '\0')
		return (ft_strdup(""));
	len -= i;
	start = i;
	i = ft_strlen(s) - 1;
	while (i > start && ft_strchr(set, s[i]))
	{
		i--;
		len--;
	}
	dest = ft_substr(s, start, len);
	return (dest);
}
