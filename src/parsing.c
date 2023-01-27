/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 12:27:01 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/01/27 09:08:07 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*ft_return_path(char **allpaths, char *path)
{
	int	i;

	if (!*allpaths || !allpaths)
		return (NULL);
	i = -1;
	while (allpaths[++i])
		free(allpaths[i]);
	free(allpaths);
	return (path);
}

char	*ft_parsing_path(char **env, char *cmd)
{
	int		i;
	char	**allpaths;
	char	*path;
	char	*temp;

	i = 0;
	while (ft_strncmp(env[i], "PATH=", 5) != 0)
		i++;
	allpaths = ft_split(env[i], ':');
	i = -1;
	while (allpaths[++i])
	{
		temp = ft_strjoin(allpaths[i], "/");
		path = ft_strjoin(temp, cmd);
		free(temp);
		if (access(path, F_OK) == 0)
			return (ft_return_path(allpaths, path));
		free(path);
	}
	i = -1;
	while (allpaths[++i])
		free(allpaths[i]);
	free(allpaths);
	return (NULL);
}
