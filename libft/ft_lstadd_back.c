#include "libft.h"
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*k;

	if (lst && *lst)
	{
		k = ft_lstlast(*lst);
		k->next = new;
	}
	else if (lst)
	{
		*lst = new;
	}
}
