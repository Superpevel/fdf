/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selbert <selbert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 13:25:49 by selbert           #+#    #+#             */
/*   Updated: 2021/09/25 13:25:51 by selbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	sym;

	ptr = ((unsigned char *) s);
	sym = ((unsigned char) c);
	while (n--)
	{
		if (*ptr == sym)
		{
			return (ptr);
		}
		ptr++;
	}
	return (NULL);
}
