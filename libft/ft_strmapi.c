#include "libft.h"
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*result;

	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	result = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!result)
		return (NULL);
	ft_strlcpy(result, s, (ft_strlen(s) + 1));
	while (result[i] != '\0')
	{
		result[i] = (*f)(i, result[i]);
		i++;
	}
	return (result);
}
