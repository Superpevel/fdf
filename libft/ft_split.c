#include "libft.h"

static size_t	ft_count_words(char const *s, char c)
{
	size_t	words;

	words = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			while (*s && *s != c)
				s++;
			words++;
		}
	}
	return (words);
}

static char	*ft_get_word(char *word, char c)
{
	char	*start;

	start = word;
	while (*word && *word != c)
		word++;
	*word = '\0';
	return (ft_strdup(start));
}

char	**ft_get_words(char *s, char c, size_t words_count, size_t i)
{
	char	**words;
	char	*word;

	words = (char **)ft_memloc_bonus(sizeof(char *) * (words_count + 1));
	if (words)
	{
		while (i < words_count)
		{
			while (*s == c)
				s++;
			if (*s)
			{
				word = ft_get_word(s, c);
				if (!(word))
				{
					ft_free_words_bonus(words, i);
					return (NULL);
				}
				words[i++] = word;
				s += (ft_strlen(word) + 1);
			}
		}
		words[i] = NULL;
	}
	return (words);
}

char	**ft_split(char const *s, char c)
{
	char	**words;
	char	*line;
	size_t	i;

	i =0;
	if (!s)
		return (NULL);
	line = ft_strdup((char *)s);
	if (!line)
		return (NULL);
	if (!c)
		return (NULL);
	words = ft_get_words(line, c, ft_count_words(line, c), i);
	free(line);
	return (words);
}
