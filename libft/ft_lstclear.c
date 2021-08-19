#include "libft.h"
void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;

	while (*lst != NULL)
	{
		tmp = *lst;
		if (tmp->content)
		{
			del(tmp->content);
			tmp->content = NULL;
		}
		*lst = tmp->next;
		free(tmp);
	}
	lst = NULL;
}
