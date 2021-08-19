#include "libft.h"
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*new;

	if (!s1)
		return (NULL);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	new = malloc(sizeof(char) * (i + j + 1));
	if (!new)
		return (NULL);
	k = -1;
	while (++k < i)
		new[k] = s1[k];
	j = k + j;
	i = 0;
	while (k < j)
	{
		new[k] = s2[i];
		k++;
		i++;
	}
	new[k] = '\0';
	return (new);
}
