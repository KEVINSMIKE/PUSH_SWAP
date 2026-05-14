/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballo <mballo@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 10:15:32 by mballo            #+#    #+#             */
/*   Updated: 2026/05/12 16:52:39 by mballo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_ps *ps)
{
	ft_swap(&ps->a);
	ft_putstr("sa\n");
	ps->ops.sa++;
}

void	ft_sb(t_ps *ps)
{
	ft_swap(&ps->b);
	ft_putstr("sb\n");
	ps->ops.sb++;
}

void	ft_ss(t_ps *ps)
{
	ft_swap(&ps->a);
	ft_swap(&ps->b);
	ft_putstr("ss\n");
	ps->ops.ss++;
}

void	ft_pa(t_ps *ps)
{
	ft_push(&ps->a, &ps->b);
	ft_putstr("pa\n");
	ps->ops.pa++;
}
void	ft_pb(t_ps *ps)
{
	ft_push(&ps->b, &ps->a);
	ft_putstr("pb\n");
	ps->ops.pb++;
}
