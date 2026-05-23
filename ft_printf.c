/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_push_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballo <mballo@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 09:27:31 by mballo            #+#    #+#             */
/*   Updated: 2026/05/06 09:27:56 by mballo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_printf_fd(int fd, const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			count += ft_find_arg(fd, format[i], args);
		}
		else
			count += ft_putchar_fd(format[i], fd);
		i++;
	}
	va_end(args);
	return (count);
}

int	ft_putfloat_fd(double nbr, int fd)
{
	int	entier;
	int	decimal;
	int	count;

	count = 0;
	entier = (int)(nbr * 100);
	decimal = (int)(nbr * 10000) % 100;
	count += ft_putnbr(entier, fd);
	count += ft_putchar_fd('.', fd);
	count += ft_putnbr(decimal, fd);
	return (count);
}

int	ft_find_arg(int fd, char c, va_list args)
{
	if (c == 'c')
		return (ft_putchar_fd(va_arg(args, int), fd));
	else if (c == 's')
		return (ft_putstr_fd(va_arg(args, char *), fd));
	else if (c == 'p')
		return (ft_putaddress(fd, (long unsigned int)va_arg(args, void *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(args, int), fd));
	else if (c == 'u' || c == 'x' || c == 'X')
		return (ft_putnbrbase(fd, va_arg(args, unsigned int), c));
	else if (c == '%')
		return (ft_putchar_fd('%', fd));
	else if (c == 'f')
		return (ft_putfloat_fd(va_arg(args, double), fd));
	return (0);
}
int    ft_putchar(char c)
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