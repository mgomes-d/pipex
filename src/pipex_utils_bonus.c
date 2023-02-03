/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 10:59:06 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/02/03 10:15:49 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_here_doc_utils(int *pipefd, char *limiter)
{
	char	*line;

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

void	ft_here_doc(char *limiter, int ac)
{
	int		pipefd[2];
	int		ret;

	if (ac < 6)
		ft_error(1);
	if (pipe(pipefd) == -1)
		exit(EXIT_FAILURE);
	ret = fork();
	if (ret == 0)
		ft_here_doc_utils(pipefd, limiter);
	else
	{
		close (pipefd[1]);
		ft_dup2andclose(pipefd[0], STDIN_FILENO);
		wait(NULL);
	}
}

void	ft_error(int error)
{
	if (error == 0)
		perror("Error");
	else if (error == 1)
		perror("$RES_REAL: ambiguous redirect\n");
	exit(EXIT_FAILURE);
}

int	ft_open_file(char *av, int i)
{
	int	file;

	file = 0;
	if (i == 0)
		file = open(av, O_RDONLY, 0644);
	else if (i == 1)
		file = open(av, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (i == 2)
		file = open(av, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (file == -1 && i == 0)
	{
		perror(av);
		exit(EXIT_FAILURE);
	}
	else if (file == -1)
		ft_error(0);
	return (file);
}
