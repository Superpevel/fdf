/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selbert <selbert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 13:25:03 by selbert           #+#    #+#             */
/*   Updated: 2021/09/25 13:36:46 by selbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_j(int i)
{
	size_t	j;

	j = 0;
	if (i == 0)
		return (1);
	if (i < 0)
		j++;
	while (i != 0)
	{
		i = i / 10;
		j++;
	}
	return (j);
}

char	*ft_fill2(char *str, size_t i, size_t j, int n)
{
	while (i < j--)
	{
		str[j] = (n % 10) + '0';
		n = n / 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	j = ft_j(n);
	str = (char *)malloc(sizeof(char) * (j + 1));
	if (!str)
		return (NULL);
	str[j] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		n = n * -1;
		i++;
	}
	return (ft_fill2(str, i, j, n));
}
