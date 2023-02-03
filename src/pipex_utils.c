/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:25:55 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/02/03 10:44:42 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_executation(char *arg, char **env)
{
	char	*path;
	char	**cmd;
	int		i;

	i = -1;
	cmd = ft_split(arg, ' ');
	path = ft_parsing_path(env, cmd[0]);
	if (!path)
	{
		perror(arg);
		while (cmd[++i])
			free(cmd[i]);
		free(cmd);
		exit(127);
	}
	if (execve(path, cmd, env) == -1)
	{
		perror("execve error\n");
		exit(EXIT_FAILURE);
	}
}

void	ft_child_process(char **arg, char **env, int *pipefd)
{
	int	filein;

	close(pipefd[0]);
	filein = open(arg[1], O_RDONLY, 0644);
	if (filein == -1)
	{
		perror(arg[1]);
		exit(EXIT_FAILURE);
	}
	dup2(pipefd[1], STDOUT_FILENO);
	close(pipefd[1]);
	dup2(filein, STDIN_FILENO);
	close(filein);
	ft_executation(arg[2], env);
	exit(EXIT_SUCCESS);
}

void	ft_parent_process(char **arg, char **env, int *pipefd)
{
	int	fileout;

	close(pipefd[1]);
	fileout = open(arg[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fileout == -1)
		exit(EXIT_FAILURE);
	dup2(pipefd[0], STDIN_FILENO);
	close(pipefd[0]);
	dup2(fileout, STDOUT_FILENO);
	close(fileout);
	ft_executation(arg[3], env);
}
