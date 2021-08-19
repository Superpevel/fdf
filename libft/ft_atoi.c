#include "libft.h"

int	is_space(char c)
{
	if (c == '\n' || c == '\t' || c == '\v' || c == '\f' || c == '\r' || c == ' ')
		return (1);
	else
		return (0);
}

int	is_oper(char c)
{
	if (c == '+' || c == '-')
		return (1);
	else
		return (0);
}

int	ft_isdigit1 (char c)
{
	if ((c >= '0') && (c <= '9'))
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int i;
	int neg;
	int res;

	i = 0;
	res = 0;
	neg = 1;
	while (is_space(str[i]))
		i++;
	if (str[i] == '-')
	{
		neg = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] && (ft_isdigit1(str[i])))
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * neg);
}
