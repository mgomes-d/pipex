/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:55:40 by mgomes-d          #+#    #+#             */
/*   Updated: 2022/10/10 17:39:22 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	lstsize;

	if (!lst)
		return (0);
	lstsize = 0;
	while (lst)
	{
		lst = lst->next;
		lstsize++;
	}
	return (lstsize);
}
