/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 12:21:05 by mgomes-d          #+#    #+#             */
/*   Updated: 2022/10/13 11:04:13 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	srcsize;
	size_t	dstsize1;

	if ((!src || !dst) && dstsize == 0)
		return (0);
	dstsize1 = ft_strlen(dst);
	srcsize = ft_strlen(src);
	i = 0;
	if (dstsize == 0 || (dstsize < dstsize1))
		return (srcsize + dstsize);
	while (src[i] && i + dstsize1 < dstsize - 1)
	{
		dst[dstsize1 + i] = src[i];
		i++;
	}
	dst[dstsize1 + i] = '\0';
	return (dstsize1 + srcsize);
}
