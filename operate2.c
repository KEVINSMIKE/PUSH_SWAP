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

void	ra(t_ps *ps)
{
	rotate(&ps->a);
	ft_putstr("ra\n");
	ps->ops.ra++;
}
void	rb(t_ps *ps)
{
	rotate(&ps->b);
	ft_putstr("rb\n");
	ps->ops.rb++;
}

void	rr(t_ps *ps)
{
	ft_rotate(&ps->a);
	ft_rotate(&ps->b);
	ft_putstr("rr\n");
	ps->ops.rr++;
}

void	rra(t_ps *ps)
{
	ft_reverse_rotate(&ps->a);
	ft_putstr("rra\n");
	ps->ops.rra++;
}
void	rra(t_ps *ps)
{
	ft_reverse_rotate(&ps->b);
	ft_putstr("rrb\n");
	ps->ops.rrb++;
}