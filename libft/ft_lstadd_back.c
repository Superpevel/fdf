/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selbert <selbert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 13:25:06 by selbert           #+#    #+#             */
/*   Updated: 2021/09/25 13:25:08 by selbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
