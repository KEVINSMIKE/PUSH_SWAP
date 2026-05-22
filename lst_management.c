/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_management.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballo <mballo@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 07:45:59 by mballo            #+#    #+#             */
/*   Updated: 2026/05/12 09:56:52 by mballo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_list **lst)
{
	t_list	*a;
	t_list	*b;

	if (!lst || !*lst || !(*lst)->next)
		return ;
	a = (*lst);
	b = (*lst)->next;
	a->next = b->next;
	b->next = a;
	*lst = b;
}

void	ft_push(t_list **lsta, t_list **lstb)
{
	t_list	*tmp;

	if(!*lsta)
		return ;
	tmp = (*lsta);
	(*lsta) = (*lsta)->next;
	tmp->next = (*lstb);
	(*lstb) = tmp;
}

void	ft_rotate(t_list **lst)
{
	t_list	*first;
	t_list	*last;

	if (!lst || !*lst || !(*lst)->next)
    	return ;
	first = (*lst);
	last = (*lst);
	while((last)->next)
		last = last->next;
	last->next = first;
	(*lst) = first->next;
	first->next = NULL;
}

void	ft_reverse_rotate(t_list **lst)
{
	t_list	*store;
	t_list	*last;

	if (!lst || !*lst || !(*lst)->next)
		return ;
	store = (*lst);
	while(store->next->next)
		store = store->next;
	last = store->next;
	store->next = NULL;
	last->next = (*lst);
	(*lst) = last;
}