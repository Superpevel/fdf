#include "libft.h"

size_t	max_len(char const *s, unsigned int start)
{
	size_t	i;

	i = ft_strlen(s) - start ;
	return (i);
}

char	*ft_sub_fill(char const *s, unsigned int start, size_t len, char *sub)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		sub[i] = s[start];
		i++;
		start++;
	}
	sub[i] = '\0';
	return (sub);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	j;

	if (!s)
		return (NULL);
	if (start >= (unsigned int)ft_strlen(s))
		return (ft_strdup(""));
	j = max_len(s, start);
	if (len < j)
	{
		sub = malloc(sizeof(char) * (len + 1));
		if (!(sub))
			return (NULL);
	}
	else
		sub = malloc(sizeof(char) * (j + 1));
	if (!(sub))
		return (NULL);
	return (ft_sub_fill(s, start, len, sub));
}
