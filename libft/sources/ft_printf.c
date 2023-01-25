/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 13:32:36 by mgomes-d          #+#    #+#             */
/*   Updated: 2022/10/21 15:33:19 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	va_start(args, format);
	i = 0;
	count = 0;
	while (i < ft_strlen((char *)format))
	{
		if (format[i] == '%')
		{
			i++;
			count = ft_format(&args, count, format[i]);
		}
		else
			count += ft_putchar(format[i]);
		i++;
		va_end (args);
	}
	return (count);
}

int	ft_format(va_list *args, int count, char c)
{
	char	*num;
	char	*lowhex;
	char	*highhex;

	num = "0123456789";
	lowhex = "0123456789abcdef";
	highhex = "0123456789ABCDEF";
	if (c == 'c')
		count += ft_putchar(va_arg(*args, int));
	else if (c == 's')
		count += ft_putstr(va_arg(*args, char *));
	else if (c == 'p')
		count += ft_putpointer(va_arg(*args, unsigned long));
	else if (c == 'd' || c == 'i')
		count += ft_putnumber(va_arg(*args, int), num, 10);
	else if (c == 'u')
		count += ft_printunsigned(va_arg(*args, unsigned int), num, 10);
	else if (c == 'x')
		count += ft_printhexlow(va_arg(*args, unsigned int), lowhex, 16);
	else if (c == 'X')
		count += ft_printhexhigh(va_arg(*args, unsigned int), highhex, 16);
	else
		count += ft_putchar(c);
	return (count);
}
