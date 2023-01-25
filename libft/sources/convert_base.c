/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:30:40 by mgomes-d          #+#    #+#             */
/*   Updated: 2022/12/26 13:41:20 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_convert_base(unsigned long nbr, char *base, unsigned int len)
{
	int	ret;

	if (nbr < len)
	{
		write(1, &base[nbr], 1);
		return (1);
	}
	ret = ft_convert_base(nbr / len, base, len);
	return (ret + ft_convert_base(nbr % len, base, len));
}

int	ft_printunsigned(unsigned int nbr, char *base, unsigned int len)
{
	int	ret;

	ret = ft_convert_base((unsigned long)nbr, base, len);
	return (ret);
}

int	ft_putnumber(int nbr, char *base, unsigned int len)
{
	int				ret;
	unsigned int	nb;

	ret = 0;
	nb = (unsigned int)nbr;
	if (nbr < 0)
	{
		write (1, "-", 1);
		nb = (unsigned int)-nbr;
		ret++;
	}
	ret += ft_convert_base((unsigned long)nb, base, len);
	return (ret);
}

int	ft_printhexlow(unsigned int nbr, char *base, unsigned int len)
{
	int	ret;

	ret = ft_convert_base((unsigned long)nbr, base, len);
	return (ret);
}

int	ft_printhexhigh(unsigned int nbr, char *base, unsigned int len)
{
	int	ret;

	ret = ft_convert_base((unsigned long)nbr, base, len);
	return (ret);
}
