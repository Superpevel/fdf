/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selbert <selbert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 14:19:06 by selbert           #+#    #+#             */
/*   Updated: 2021/09/25 17:44:28 by selbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*a;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	a = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!(a))
		return (NULL);
	if (s1)
		while (s1[j] != '\0')
			a[i++] = s1[j++];
	j = 0;
	free(s1);
	if (s2)
		while (s2[j] != '\0')
			a[i++] = s2[j++];
	a[i] = '\0';
	return (a);
}

int	ft_strchr(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
		{
			return (1);
		}
		i++;
	}
	return (0);
}

char	*check(char *remain, char **line)
{
	int		i;
	char	*tmp;

	tmp = 0;
	i = 0;
	if (!remain)
	{
		*line = 0;
		return (0);
	}
	while (remain[i])
	{
		if (remain[i] == '\n')
			break ;
		i++;
	}
	if (remain[i])
		tmp = ft_substr(remain, i + 1, (ft_strlen(remain) - i));
	*line = ft_substr(remain, 0, i);
	free(remain);
	return (tmp);
}

int	ft_oper(int was_read, char *buf)
{
	free(buf);
	if (was_read == -1)
		return (-1);
	if (was_read == 0)
		return (0);
	return (1);
}

int	get_next_line(int fd, char **line)
{
	char		*buf;
	int			was_read;
	static char	*remain;

	if (read(fd, 0, 0) || !line || BUFFER_SIZE <= 0)
		return (-1);
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (-1);
	was_read = 1;
	while (!ft_strchr(remain) && was_read > 0)
	{
		was_read = read(fd, buf, BUFFER_SIZE);
		buf[was_read] = '\0';
		remain = ft_strjoin(remain, buf);
	}
	remain = check(remain, line);
	return (ft_oper(was_read, buf));
}
