/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 13:16:55 by mgomes-d          #+#    #+#             */
/*   Updated: 2022/10/13 10:54:24 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	sizes;

	if (!s || !c)
		return (NULL);
	sizes = ft_strlen(s) + 1;
	while (sizes > 0)
	{
		sizes--;
		if (s[sizes] == (char)c)
			return ((char *)&s[sizes]);
	}
	return (NULL);
}
