/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballo <mballo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 07:48:19 by mballo            #+#    #+#             */
/*   Updated: 2026/05/13 13:45:31 by mballo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define INT_MIN -2147483648
# define INT_MAX  2147483647
# define LONG_MAX_VAL 9223372036854775807
typedef struct s_list
{
	int		nb;
	struct s_list *next;
}	t_list;

typedef struct s_ps
{
	t_list	*a;
	t_list	*b;
	int		size;
	double	disorder;
	t_strategy	strategy;
	int		bench;
	t_ops	ops;
}	t_ps;

typedef	enum e_strategy
{
	STRAT_ADAPTIVE = 0,
	STRAT_SIMPLE,
	STRAT_MEDIUM,
	STRAT_COMPLEX,
}	t_strategy;

typedef struct s_ops
{
	int sa; int sb; int ss;
	int pa; int pb;
	int ra; int rb; int rr;
	int rra; int rrb; int rrr;
}	t_ops;

# include <stdlib.h>
# include <unistd.h>


#endif