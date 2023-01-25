/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 10:48:46 by mgomes-d          #+#    #+#             */
/*   Updated: 2022/10/09 18:37:46 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_checkset(char const *set, char c)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	if (c == '\0')
		return (1);
	return (0);
}

int	ft_checkend(char const *s1, char const *set)
{
	size_t	len;

	len = ft_strlen(s1);
	while (len > 0)
	{
		if (!ft_checkset(set, s1[len]))
		{
			return (len);
		}
		len--;
	}
	return (len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	while (s1[i] && ft_checkset(set, s1[i]))
		i++;
	j = 0;
	while (s1[i] && (int)(i + j) <= ft_checkend(s1, set))
		j++;
	str = malloc(sizeof(char) * (j + 1));
	if (!str)
		return (NULL);
	ft_memcpy(str, s1 + i, j);
	i++;
	str[j] = '\0';
	return (str);
}
