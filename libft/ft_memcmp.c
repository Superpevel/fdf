/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selbert <selbert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 13:25:54 by selbert           #+#    #+#             */
/*   Updated: 2021/09/25 13:25:55 by selbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ptr;
	unsigned char	*cp;

	ptr = ((unsigned char *) s1);
	cp = ((unsigned char *) s2);
	while (n--)
	{
		if (*ptr != *cp)
		{
			return (*ptr - *cp);
		}
		cp++;
		ptr++;
	}
	return (0);
}
