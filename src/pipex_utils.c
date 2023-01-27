/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:25:55 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/01/27 11:33:40 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_executation(char *arg, char **env)
{
	char	*path;
	char	**cmd;
	
	cmd = ft_split(arg, ' ');
	path = ft_parsing_path(env, cmd[0]);
	if (!path)
	{
		ft_putstr_fd("path error\n", 2);
		return;
	}
	if (execve(path, cmd, env) == -1)
	{
		ft_putstr_fd("ex error\n", 2);
		return ;
	}
}

void	ft_child_process(char **arg, char **env, int *pipefd)
{
	int	filein;

	close(pipefd[0]);
	filein = open(arg[1], O_RDONLY, 0777);
	if (filein == -1)
		return ;
	dup2(pipefd[1], STDOUT_FILENO);
	dup2(filein, STDIN_FILENO);
	ft_executation(arg[2], env);
}

void	ft_parent_process(char **arg, char **env, int *pipefd)
{
	int	fileout;

	close(pipefd[1]);
	fileout = open(arg[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fileout == -1)
		return;
	dup2(pipefd[0], STDIN_FILENO);
	dup2(fileout, STDOUT_FILENO);
	ft_executation(arg[3], env);
}