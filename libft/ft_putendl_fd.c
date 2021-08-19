#include "libft.h"

void	ft_putendl_fd(char const *s, int fd)
{
	int	i;
	int	n;

	i = 0;
	n = '\n';
	if (s)
	{
		while (s[i] != '\0')
		{
			write(fd, &s[i], 1);
			i++;
		}
	}
	write(fd, &n, 1);
}
