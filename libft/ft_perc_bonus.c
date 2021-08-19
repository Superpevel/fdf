#include "libft.h"

void	ft_freestr_bonus(char **as)
{
	if (as && *as)
	{
		free(*as);
		*as = NULL;
	}
}

void	*ft_memloc_bonus(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (ptr)
		ft_bzero(ptr, size);
	return (ptr);
}

void	ft_free_words_bonus(char **words, size_t i)
{
	size_t	j;

	j = 0;
	while (j < i)
		ft_freestr_bonus(&(words[j]));
	free(*words);
}
