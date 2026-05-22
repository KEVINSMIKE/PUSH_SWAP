/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimax.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballo <mballo@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 08:51:57 by mballo            #+#    #+#             */
/*   Updated: 2026/05/22 08:52:00 by mballo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
 
void	ft_minimax(t_ps *head)
{
	int		max;
	t_list	*pile;
 
	while (head->a)
	{
		pile = head->a;
		max = find_max(pile);
		while (head->a->nb != max)
			ft_ra(head);
		ft_pb(head);
	}
	while (head->b)
		ft_pa(head);
}