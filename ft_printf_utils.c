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

int	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

int	ft_putstr_fd(char *str, int fd)
{
	int	i;
  
	i = -1;
	while (str[++i])
		ft_putchar_fd(str[i], fd);
	return (i);
}

int	ft_putnbrbase(int fd, long unsigned int nbr, char base)
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
		count += ft_putnbrbase(fd, nbr / convert_base, base);
	count += _ft_putchar_fd(basechar[nbr % convert_base], fd);
	return (count);
}

int	ft_putaddress(int fd, long unsigned int c)
{
	int	count;

	count = 0;
	if (c == 0)
	{
		count += ft_putstr_fd("0x0", fd);
		return (count);
	}
	count += ft_putstr_fd("0x", fd);
	count += ft_putnbrbase(fd, (unsigned long)c, 'x');
	return (count);
}

int	ft_putnbr(int nbr, int fd)
{
	int	count;

	count = 0;
	if (nbr == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return (11);
	}
	if (nbr < 0)
	{
		write(fd, "-", 1);
		count++;
		nbr = -nbr;
	}
	if (nbr >= 10)
		count += ft_putnbr(nbr / 10, fd);
	count += ft_putchar_fd(nbr % 10 + '0', fd);
	return (count);
}
