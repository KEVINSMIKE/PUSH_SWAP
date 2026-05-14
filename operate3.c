/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballo <mballo@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 12:45:10 by mballo            #+#    #+#             */
/*   Updated: 2026/05/12 16:54:27 by mballo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rrr(t_ps *ps)
{
	ft_reverse_rotate(&ps->a);
	ft_reverse_rotate(&ps->b);
	ft_putstr("rrr\n");
	ps->ops.rrr++;
}