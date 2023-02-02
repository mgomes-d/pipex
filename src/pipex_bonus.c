/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 10:58:49 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/02/02 11:24:39 by mgomes-d         ###   ########.fr       */
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
		ft_putstr_fd(arg, 2);
		ft_putstr_fd(": command not found\n", 2);
		while (cmd[++i])
			free(cmd[i]);
		free(cmd);
		exit(127);
		return;
	}
	if (execve(path, cmd, env) == -1)
	{
		perror("execve error\n");
		exit(1);
		return ;
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
		dup2(pipefd[1], STDOUT_FILENO);
		close(pipefd[1]);
		ft_executation_b(av, env);
	}
	else
	{
		close(pipefd[1]);
		dup2(pipefd[0], STDIN_FILENO);
		close(pipefd[0]);
		waitpid(pid, NULL, 0);
	}
		
}

void	ft_here_doc(char *limiter, int ac)
{
	int		pipefd[2];
	int		ret;
	char	*line;

	if (ac < 6)
		exit(0);
	if (pipe(pipefd) == -1)
		exit(1);
	ret = fork();
	if (ret == 0)
	{
		close(pipefd[0]);
		while (1)
		{
			line = get_next_line(0);
			if (ft_strncmp(line, limiter, ft_strlen(line) - 1) == 0)
				exit(0);
			write(pipefd[1], line, ft_strlen(line));
			free(line);
		}
	}
	else
	{
		close (pipefd[1]);
		dup2(pipefd[0], STDIN_FILENO);
		close(pipefd[0]);
		wait(NULL);
	}
}

int	main(int ac, char **av, char **env)
{
	int		i;
	int		filein;
	int		fileout;
	
	if (ac < 5)
	{
		ft_putstr_fd("$RES_REAL: ambiguous redirect\n", 2);
		return (1);
	}
	if (ft_strncmp(av[1], "here_doc", 8) == 0)
	{
		i = 3;
		fileout = open(av[ac - 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (fileout == -1)
			return (1);
		ft_here_doc(av[2], ac);
	}
	else
	{
		i = 2;
		fileout = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fileout == -1)
			return (1);
		filein = open(av[1], O_RDONLY, 0777);
		if (filein == -1)
		{
			ft_putstr_fd(av[1], 2);
			ft_putstr_fd(": No such file or directory\n", 2);
			return (1);
		}
		dup2(filein, STDIN_FILENO);
		close(filein);
	}
	while (i < ac - 2)
		ft_process(av[i++], env);
	dup2(fileout, STDOUT_FILENO);
	close(fileout);
	ft_executation_b(av[ac - 2], env);
	close(fileout);
	exit(0);
}