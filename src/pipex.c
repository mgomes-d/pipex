/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 10:37:18 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/01/26 10:23:00 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **env)
{
	t_pipex data;
	int	pipefd[2];  // Stores the pipe's fds:
			    //	- pipefd[0]: read only
			    //	- pipefd[1]: write only
	pid_t	pid;	// Stores fork's return value
	char	buf;	// Stores characters read by read
	char	*cmd1;
	char	*cmd2;

	(void)ac;
	(void)av;

	if (ac != 5)
	{
		ft_putstr_fd("Arguments error\n", 2);
		return (0);
	}
	ft_parsing_env(env, &data);
	cmd1 = ft_strdup(av[1]);
	cmd2 = ft_strdup(av[2]);
	
	if (pipe(pipefd) == -1)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	//creat a child
	pid = fork();
	if (pid == -1) // protection
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0) // Child process
	{
		close(pipefd[1]);//Close the unsed write
		ft_writestr(STDOUT_FILENO, "ClidProcess\n");
		while (read(pipefd[0], &buf, 1) > 0)
		{
			// Write the read character to standard output
			write(STDOUT_FILENO, &buf, 1);
		}
		ft_writestr(STDOUT_FILENO, "\nainda child\n");
	}
	else // Parent preocess
	{
		close(pipefd[0]); // Close unused read
		ft_writestr(STDOUT_FILENO, "Parent: I'm writing a secret in this pipe...\n");
		//write into pipe
		ft_writestr(pipefd[1], "\e[33mHELLO PARENT PROCESS\e[0m");
		
	}
}
