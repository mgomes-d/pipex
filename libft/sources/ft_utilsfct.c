/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilsfct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:09:56 by mgomes-d          #+#    #+#             */
/*   Updated: 2022/10/21 15:33:39 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	len;

	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	len = 0;
	while (str[len])
		len++;
	write (1, str, len);
	return (len);
}

int	ft_putchar(char c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_putpointer(unsigned long nbr)
{
	int	i;

	write(1, "0x", 2);
	i = ft_convert_base(nbr, "0123456789abcdef", 16);
	return (i + 2);
}
