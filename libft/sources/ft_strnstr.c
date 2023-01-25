/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:08:00 by mgomes-d          #+#    #+#             */
/*   Updated: 2022/10/13 11:05:17 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	b;
	char	*preturn;

	i = 0;
	if (!haystack && len == 0)
		return (NULL);
	if ((char)needle[i] == '\0')
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		b = 0;
		if (haystack[i] == needle[b])
		{
			preturn = (char *)&haystack[i];
			while (needle[b] && haystack[i + b] == needle[b] && (i + b) < len)
			{
				b++;
				if (needle[b] == '\0')
					return (preturn);
			}
		}
		i++;
	}
	return (NULL);
}
