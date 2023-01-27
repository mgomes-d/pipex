/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 10:38:43 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/01/27 10:44:09 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"

typedef struct s_pipex
{
	char	**allpath;
}	t_pipex;

# include <stdio.h>

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <signal.h>

char	*ft_parsing_path(char **env, char *cmd);
void	ft_child_process(char **arg, char **env, int *pipefd);
void	ft_parent_process(char **arg, char **env, int *pipefd);


#endif
