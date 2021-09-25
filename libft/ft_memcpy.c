/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selbert <selbert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 13:25:57 by selbert           #+#    #+#             */
/*   Updated: 2021/09/25 13:25:59 by selbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*dp;
	const char	*sp = src;

	i = 0;
	dp = (char *)dst;
	if (!dst && !src)
		return (NULL);
	while (i < n)
	{
		*dp++ = *sp++;
		i++;
	}
	return (dst);
}
