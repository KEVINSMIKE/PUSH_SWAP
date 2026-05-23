/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballo <mballo@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 12:26:04 by mballo            #+#    #+#             */
/*   Updated: 2026/05/12 16:54:29 by mballo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_ps *ps)
{
	ft_rotate(&ps->a);
	ft_putstr("ra\n");
	ps->ops.ra++;
}

void	ft_rb(t_ps *ps)
{
	ft_rotate(&ps->b);
	ft_putstr("rb\n");
	ps->ops.rb++;
}

void	ft_rr(t_ps *ps)
{
	ft_rotate(&ps->a);
	ft_rotate(&ps->b);
	ft_putstr("rr\n");
	ps->ops.rr++;
}

void	ft_rra(t_ps *ps)
{
	ft_reverse_rotate(&ps->a);
	ft_putstr("rra\n");
	ps->ops.rra++;
}
void	ft_rrb(t_ps *ps)
{
	ft_reverse_rotate(&ps->b);
	ft_putstr("rrb\n");
	ps->ops.rrb++;
}
