/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selbert <selbert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 13:25:45 by selbert           #+#    #+#             */
/*   Updated: 2021/09/25 13:25:47 by selbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;
	char	*dest;
	char	*src1;
	char	*ptr;

	i = 0;
	ptr = 0;
	dest = (char *)dst;
	src1 = (char *)src;
	while (i < n && ptr == 0)
	{
		dest[i] = src1[i];
		if (src1[i] == ((char)c))
			ptr = dest + i + 1;
		i++;
	}
	return (ptr);
}
