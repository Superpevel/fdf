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
