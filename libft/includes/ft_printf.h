/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 15:32:39 by mgomes-d          #+#    #+#             */
/*   Updated: 2022/10/21 15:33:27 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_strlen(char *str);
int		ft_putpointer(unsigned long nbr);
int		ft_convert_base(unsigned long nbr, char *base, unsigned int len);
int		ft_printunsigned(unsigned int nbr, char *base, unsigned int len);
int		ft_putnumber(int nbr, char *base, unsigned int len);
int		ft_printhexlow(unsigned int nbr, char *base, unsigned int len);
int		ft_printhexhigh(unsigned int nbr, char *base, unsigned int len);
int		ft_format(va_list *arg, int count, char c);

#endif
