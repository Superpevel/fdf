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
