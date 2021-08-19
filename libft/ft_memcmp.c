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
