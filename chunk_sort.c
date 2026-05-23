/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballo <mballo@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 08:48:16 by mballo            #+#    #+#             */
/*   Updated: 2026/05/23 11:41:21 by mballo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_chunk_size(int size)
{
	int	i;

	i = 1;
	while (i * i < size)
		i++;
	return (i);
}

static void	fill_a(t_ps *head)
{
	int		max;
	t_list	*pile;

	while (head->b)
	{
		pile = head->b;
		max = find_max(pile);
		while (head->b->nb != max)
			ft_rb(head);
		ft_pa(head);
	}
}

void	sort_medium(t_ps *head)
{
	int	chunk_size;
	int	pos;
	int	size;

	size = ft_lst_size(&head->a);
	ft_index(&head->a);
	chunk_size = get_chunk_size(size);
	pos = 0;
	while (pos < size)
	{
		while (size > 0)
		{
			if (head->a->index >= pos && head->a->index < pos + chunk_size)
			{
				ft_pb(head);
				if (head->b && head->b->next && head->b->index < pos)
					ft_rb(head);
			}
			else
				ft_ra(head);
			size --;
		}
		pos += chunk_size;
	}
	fill_a(head);
}
