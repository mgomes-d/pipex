/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 10:38:43 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/02/03 10:44:51 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include <stdio.h>

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <signal.h>

char	*ft_parsing_path(char **env, char *cmd);
void	ft_child_process(char **arg, char **env, int *pipefd);
void	ft_parent_process(char **arg, char **env, int *pipefd);
void	ft_here_doc(char *limiter, int ac);
void	ft_error(int error);
int		ft_open_file(char *av, int i);
void	ft_dup2andclose(int src, int dest);

#endif
