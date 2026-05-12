/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballo <mballo@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 21:21:40 by mballo            #+#    #+#             */
/*   Updated: 2026/05/05 13:18:27 by mballo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
	return (i);
}

int	ft_putnbrbase(long unsigned int nbr, char base)
{
	char	*basechar;
	int		convert_base;
	int		count;

	count = 0;
	if (base == 'x')
	{
		basechar = "0123456789abcdef";
		convert_base = 16;
	}
	else if (base == 'X')
	{
		basechar = "0123456789ABCDEF";
		convert_base = 16;
	}
	else if (base == 'u')
	{
		basechar = "0123456789";
		convert_base = 10;
	}
	if (nbr >= (unsigned long) convert_base)
		count += ft_putnbrbase(nbr / convert_base, base);
	count += ft_putchar(basechar[nbr % convert_base]);
	return (count);
}

int	ft_putaddress(long unsigned int c)
{
	int	count;

	count = 0;
	if (c == 0)
	{
		count += ft_putstr("0x0");
		return (count);
	}
	count += ft_putstr("0x");
	count += ft_putnbrbase((unsigned long)c, 'x');
	return (count);
}

int	ft_putnbr(int nbr)
{
	int	count;

	count = 0;
	if (nbr == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (nbr < 0)
	{
		write(1, "-", 1);
		count++;
		nbr = -nbr;
	}
	if (nbr >= 10)
		count += ft_putnbr(nbr / 10);
	count += ft_putchar(nbr % 10 + '0');
	return (count);
}
