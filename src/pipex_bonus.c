/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 10:58:49 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/02/03 09:44:47 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_executation_b(char *arg, char **env)
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
		perror("execve error");
		exit(EXIT_FAILURE);
	}
}

void	ft_process(char *av, char **env)
{
	int		pipefd[2];
	pid_t	pid;

	if (pipe(pipefd) == -1)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	pid = fork();
	if (pid == 0)
	{
		close(pipefd[0]);
		ft_dup2andclose(pipefd[1], STDOUT_FILENO);
		ft_executation_b(av, env);
	}
	else
	{
		close(pipefd[1]);
		ft_dup2andclose(pipefd[0], STDIN_FILENO);
		waitpid(pid, NULL, 0);
	}
}

void	ft_dup2andclose(int src, int dest)
{
	dup2(src, dest);
	close(src);
}

int	main(int ac, char **av, char **env)
{
	int		i;
	int		filein;
	int		fileout;

	if (ac < 5)
		ft_error(1);
	if (ft_strncmp(av[1], "here_doc", 8) == 0)
	{
		i = 3;
		fileout = ft_open_file(av[ac - 1], 2);
		ft_here_doc(av[2], ac);
	}
	else
	{
		i = 2;
		fileout = ft_open_file(av[ac - 1], 1);
		filein = ft_open_file(av[1], 0);
		ft_dup2andclose(filein, STDIN_FILENO);
	}
	while (i < ac - 2)
		ft_process(av[i++], env);
	ft_dup2andclose(fileout, STDOUT_FILENO);
	ft_executation_b(av[ac - 2], env);
	exit(EXIT_SUCCESS);
}
