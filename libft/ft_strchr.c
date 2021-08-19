#include "libft.h"
char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	if (c == str[i])
		return (((char *)str + i));
	else
		return (NULL);
}
