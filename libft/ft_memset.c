/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selbert <selbert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 13:26:07 by selbert           #+#    #+#             */
/*   Updated: 2021/09/25 13:26:08 by selbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*dp;
	unsigned char	s;
	size_t			i;

	i = 0;
	dp = (unsigned char *)b;
	s = (unsigned char)c;
	while (i < len)
	{
		*dp++ = s;
		i++;
	}
	return (b);
}
