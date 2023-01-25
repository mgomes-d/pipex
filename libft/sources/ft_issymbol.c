/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_issymbol.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 10:14:30 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/01/19 10:08:31 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_issymbol(char c)
{
	if (c == '-')
		return (1);
	if (c == '+')
		return (1);
	else
		return (0);
}

int	ft_issymbolnumberstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
		{
			if (!ft_issymbol(str[i]) && !ft_isdigit(str[i]) && str[i] != ' ')
				return (0);
			else if (ft_issymbol(str[i]) && !ft_isdigit(str[i + 1]))
				return (0);
			else
				i++;
		}
		else
			i++;
	}
	return (1);
}
