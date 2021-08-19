#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	lst;

	i = 0;
	lst = -1;
	if (c == 0)
		return ((char *)s + ft_strlen(s));
	while (s[i] !='\0')
	{
		if (s[i] == c)
		{
			lst = i;
		}
		i++;
	}
	if (lst >= 0)
	{
		return (((char *)s + lst));
	}
	else
		return (NULL);
}
