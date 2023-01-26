/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 12:27:01 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/01/26 09:44:32 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_parsing_env(char **env, t_pipex *data)
{
	int	i;
	int	ret;

	i = 0;
	while (env[i])
	{
		ret = ft_strncmp(env[i], "PATH=", 5);
		if (ret == 0)
		{
			data->allpath = ft_split(env[i] + 5, ':');
			break ;
		}
		i++;
	}
	return ;
}