/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affiche_management.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballo <mballo@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 11:54:27 by mballo            #+#    #+#             */
/*   Updated: 2026/05/12 11:58:38 by mballo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int    ft_strcmp(char *s1, char *s2)
{
    int    i;

    i = 0;
    while (s1[i] && s1[i] == s2[i])
        i++;
    return (s1[i] - s2[i]);
}

char	*ft_get_strategy_name(t_ps *ps)
{
	if (ps->strategy == STRAT_SIMPLE)
		return ("Simple / O(n*n)");
	else if (ps->strategy == STRAT_MEDIUM)
		return ("Medium / O(n*sqrt(n)");
	else if (ps->strategy == STRAT_COMPLEX)
		return ("Complex / O(n log n)");
	else if (ps->disorder < 0.2)
		return ("Adaptive / O(n*n)");
	else if (ps->disorder < 0.5)
		return ("Adaptive / O(n sqrt(n))");
	else if (ps->disorder >= 0.5)
		return ("Adaptive / O(n log n)");
	return (NULL);
}
void	ft_print_bench(t_ps *ps)
{
	int	total;

	total = 0;
	total = ps->ops.sa + ps->ops.sb + ps->ops.ss 
	+ ps->ops.pa + ps->ops.pb + ps->ops.ra + ps->ops.rb
	+ ps->ops.rr + ps->ops.rra + ps->ops.rrb + ps->ops.rrr;
	ft_printf_fd(2,"[bench] disorder: %f \n",ps->disorder *100);
	ft_printf_fd(2,"[bench] strategy: %s \n", ft_get_strategy_name(ps));
	ft_printf_fd(2,"[bench] total_ops: %d\n", total);
	ft_printf_fd(2,"[bench] sa: %d sb: %d ss: %d pa: %d pb: %d\n",ps->ops.sa,
		ps->ops.sb, ps->ops.ss, ps->ops.pa, ps->ops.pb);
	ft_printf_fd(2,"[bench] ra: %d rb: %d rr: %d rra: %d rrb: %d rrr: %d\n", 
		ps->ops.ra, ps->ops.rb, ps->ops.rr, ps->ops.rra, ps->ops.rrb, ps->ops.rrr);
}