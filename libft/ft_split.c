/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selbert <selbert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 13:26:34 by selbert           #+#    #+#             */
/*   Updated: 2021/09/25 13:26:35 by selbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_word(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			i++;
			while (*s && *s != c)
				s++;
		}
	}
	return (i);
}

void	*ft_next_word(char const **s, char c)
{
	char	*str;
	size_t	i;

	i = 0;
	while ((*s)[i] && (*s)[i] != c)
		i++;
	str = ft_substr(*s, 0, i);
	if (!str)
		return (NULL);
	*s = *s + i;
	return (str);
}

void	*ft_free_str(char **new, size_t i)
{
	while (i--)
		free(new[i]);
	free(new);
	return (NULL);
}

char	**ft_fill_split(const char *s, char c, char **new)
{
	size_t	i;

	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			new[i] = ft_next_word(&s, c);
			if (new[i] == NULL)
				return (ft_free_str(new, i));
			i++;
		}
	}
	new[i] = NULL;
	return (new);
}

char	**ft_split(char const *s, char c)
{
	char	**new;
	int		words;

	if (!s)
		return (NULL);
	words = ft_count_word(s, c);
	new = (char **)malloc(sizeof(char *) * (words + 1));
	if (!new)
		return (NULL);
	return (ft_fill_split(s, c, new));
}
