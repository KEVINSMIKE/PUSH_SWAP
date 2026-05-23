/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballo <mballo@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 08:45:55 by mballo            #+#    #+#             */
/*   Updated: 2026/05/23 12:26:35 by mballo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max(t_list *pa)
{
	int	max;

	if (!pa)
		return (0);
	max = pa->nb;
	while (pa)
	{
		if (pa->nb > max)
			max = pa->nb;
		pa = pa->next;
	}
	return (max);
}

static int	max_bit(int size)
{
	int	bits;
	int	index_max;

	bits = 0;
	index_max = size - 1;
	if (index_max <= 0)
		return (1);
	while ((index_max >> bits) != 0)
		bits++;
	return (bits);
}

void	ft_radixsort(t_ps *head)
{
	int	bit;
	int	bit_max;
	int	len_lst;
	int	size;

	size = ft_lst_size(&head->a);
	bit_max = max_bit(size);
	bit = 0;
	while (bit < bit_max)
	{
		len_lst = size;
		while (len_lst > 0)
		{
			if ((head->a->index >> bit) & 1)
				ft_ra(head);
			else
				ft_pb(head);
			len_lst--;
		}
		while (head->b)
			ft_pa(head);
		bit++;
	}
}
