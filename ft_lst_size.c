/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballo <mballo@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 17:07:31 by mballo            #+#    #+#             */
/*   Updated: 2026/05/22 09:50:21 by mballo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lst_size(t_list **lst)
{
    int		i;
	t_list	*indice;
	
	if (!lst || !*lst)
		return (0);
	indice = *lst;
	i = 0;
	while (indice)
	{
		indice = indice->next;
		i++;
	}
	return (i);
}

int	ft_is_sort(t_list **lst)
{
	t_list	*indice;

	if(!lst || !*lst)
		return (1);
	indice = *lst;
	while (indice && indice->next)
	{
		if (indice->nb > indice->next->nb)
			return (0);
		indice = indice->next;
	}
	return (1);
}

void	ft_index(t_list **lst)
{
	t_list	*index;
	t_list	*run;
	int		i;

	index = *lst;
	
	while (index)
	{
		i = 0;
		run = *lst;
		while (run)
		{
			if (index->nb > run->nb)
				i++;
			run = run->next;
		}
		index->index = i;
		index = index->next;
	}
}
double	ft_desorder(t_list **lst)
{
	t_list	*list;
	t_list	*index;
	double	pair;
	double	mistake;
	
	if (!lst || !*lst)
		return (0);
	mistake = 0;
	pair = ft_lst_size(lst) * (ft_lst_size(lst) - 1) / 2;
	list = *lst;
	while (list)
	{
		index = list->next;
		while (index)
		{
			if (index->nb > list->nb)
				mistake++;
			index = index->next;
		}
		list = list->next;
	}
	return (mistake / pair);
}
