/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballo <mballo@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 07:23:09 by mballo            #+#    #+#             */
/*   Updated: 2026/05/07 07:23:14 by mballo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list *ft_newlst(int content)
{
	t_list *new_lst;
	
	new_lst = malloc(sizeof(t_list));
	if (!new_lst)
		return (NULL);
	new_lst->content = content;
	new_lst->next  = NULL;
	return(new_lst);
}

t_list *ft_lstaddfront(t_list **lst, t_list *elem)
{
	if (!lst || !elem)
		return (NULL);
	elem->next = *lst;
	*lst = elem;
	return (lst);
}

int	ft_lstlen(t_list *lst)
{
	int	i;

	if (!lst)
		return (0);
	i = 0;
	while (lst->next)
		i++;
	return (i);
}
