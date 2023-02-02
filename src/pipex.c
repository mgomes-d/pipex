/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 10:37:18 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/02/02 11:26:06 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **env)
{
	int		pipefd[2];  // Stores the pipe's fds:		    //	- pipefd[0]: read only			    //	- pipefd[1]: write only
	pid_t	pid;	// Stores fork's return value
	
	if (ac != 5)
	{
		ft_putstr_fd("$RES_REAL: ambiguous redirect\n", 2);
		return (1);
	}
	if (pipe(pipefd) == -1)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	pid = fork();
	if (pid == -1) // protection
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0) // Child process
		ft_child_process(av, env, pipefd);
	else // Parent preocess
		ft_parent_process(av, env, pipefd);
	waitpid(pid, NULL, 0);
}
