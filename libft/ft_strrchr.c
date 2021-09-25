/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selbert <selbert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 13:27:23 by selbert           #+#    #+#             */
/*   Updated: 2021/09/25 13:36:25 by selbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	lst;

	i = 0;
	lst = -1;
	if (c == 0)
	{
		return ((char *) s + ft_strlen(s));
	}
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			lst = i;
		}
		i++;
	}
	if (lst >= 0)
	{
		return (((char *)s + lst));
	}
	else
		return (NULL);
}
