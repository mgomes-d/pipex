/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 09:46:20 by mgomes-d          #+#    #+#             */
/*   Updated: 2022/10/13 10:52:21 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*ptr;
	char	*ptr2;
	size_t	i;

	if (!dst && !src)
		return (NULL);
	i = 0;
	ptr = (char *)dst;
	ptr2 = (char *)src;
	if (len < 0)
		return (NULL);
	if (ptr > ptr2)
	{
		while (len)
		{
			len--;
			ptr[len] = ptr2[len];
		}
	}
	while (i < len)
	{
		ptr[i] = ptr2[i];
		i++;
	}
	return (dst);
}
