/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballo <mballo@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 20:03:43 by mballo            #+#    #+#             */
/*   Updated: 2026/05/14 20:03:43 by mballo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main (int argc, char **argv)
{

    t_ps    ps;
	int	start;

    ps.a        = NULL;
    ps.b        = NULL;
    ps.size     = 0;
    ps.disorder = 0;
    ps.bench    = 0;
    ps.strategy = STRAT_ADAPTIVE;
    ps.ops.sa   = 0;
    ps.ops.sb   = 0;
    ps.ops.ss   = 0;
    ps.ops.pa   = 0;
    ps.ops.pb   = 0;
    ps.ops.ra   = 0;
    ps.ops.rb   = 0;
    ps.ops.rr   = 0;
    ps.ops.rra  = 0;
    ps.ops.rrb  = 0;
    ps.ops.rrr  = 0;

	

	if (argc > 1)
	{
		start = 1;
		while (argv[start] && argv[start][0] == '-' && argv[start][1] == '-')
		{
			if (start > 3)
			{
				ft_putstr_fd("Error\n",2);
				return (0);
			}
			if (ft_strcmp(&argv[start][2], "simple") == 0)
				ps.strategy = STRAT_SIMPLE;
			else if (ft_strcmp(&argv[start][2], "medium") == 0)
				ps.strategy = STRAT_MEDIUM;
			else if (ft_strcmp(&argv[start][2], "complex") == 0)
				ps.strategy = STRAT_COMPLEX;
			else if (ft_strcmp(&argv[start][2], "adaptive") == 0)
				ps.strategy = STRAT_ADAPTIVE;
			else if (ft_strcmp(&argv[start][2], "bench") == 0)
				ps.bench = 1;
			start++;
		}
		ps.a = ft_create_lst (argc - start, argv + start);
		if (!ps.a)
			return (ft_lst_free(&ps.a),0);
		if (ft_have_double (&ps.a) == -1)
			return (ft_lst_free(&ps.a),0);
		ft_index(&ps.a);
		ps.disorder = ft_desorder(&ps.a);
		if (ft_is_sorted(&ps.a) == 0)
		{
			ft_algo(&ps);
		}
		ft_lst_free(&ps.a);
		ft_lst_free(&ps.b);
		return (0);
	}
}
