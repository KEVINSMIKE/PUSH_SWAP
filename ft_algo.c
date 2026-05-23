/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballo <mballo@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 08:52:58 by mballo            #+#    #+#             */
/*   Updated: 2026/05/23 12:29:28 by mballo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_low_disorder(t_ps *ps)
{
	int	sorted;
	int	i;

	sorted = 0;
	while (!sorted)
	{
		sorted = 1;
		i = ft_lst_size(&ps->a);
		while (i > 1)
		{
			if (ps->a->nb > ps->a->next->nb)
			{
				ft_sa(ps);
				sorted = 0;
			}
			ft_ra(ps);
			i--;
		}
	}
}

void	ft_algo(t_ps *ps)
{
	if (ft_is_sort(&ps->a))
		return ;
	if (ps->strategy == STRAT_SIMPLE)
		ft_minimax(ps);
	else if (ps->strategy == STRAT_MEDIUM)
		sort_medium(ps);
	else if (ps->strategy == STRAT_COMPLEX)
		ft_radixsort(ps);
	else
	{
		if (ps->disorder < 0.2)
			sort_low_disorder(ps);
		else if (ps->disorder < 0.5)
			sort_medium(ps);
		else
			ft_radixsort(ps);
	}
}
