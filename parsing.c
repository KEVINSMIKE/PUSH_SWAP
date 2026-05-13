/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballo <mballo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 16:57:53 by mballo            #+#    #+#             */
/*   Updated: 2026/05/13 13:42:26 by mballo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_valid_int(char *str)
{
	int	i;

	i = 0;
	
	while (str[i])
	{
		if (str[0] == '-' || str[0] == '+')
			i++;
		if (!str[i])
			return (0);
		if (!(str[i] >= '0' && str[i] <='9'))
			return (0);
	}
	return (1);
}

long	ft_atoi(char *str)
{
	int		i;
	int		sign;
	long	res;

	i = 0;
	sign = 1;
	res = 0;

	if (str[0] == '-' || str[0] == '+')
	{
		if (str[0] == '-')
			sign = -sign;
		i++;
	}
	while (str[i])
		res = res * 10 + str[i++] - '0';
	res = res * sign;
	if (res > INT_MAX || res <INT_MIN)
	{
		ft_putstr_fd("Error\n",2);
		return (9999999999);
	}
	return (res);
}

int ft_have_double(t_list **lst)
{
	t_list	*index;
	t_list	*comp;

	index = (*lst);
	while (index->next)
	{
		comp = index->next;
		while(comp)
		{
			if (index->nb == comp->nb)
			{
			ft_putstr_fd("Error\n",2);
			return (-1);
			}
			comp = comp->next;
		}
		index = index->next;
	}
	return (0);
}