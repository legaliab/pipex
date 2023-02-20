/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alabdull <alabdull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 02:26:38 by alabdull          #+#    #+#             */
/*   Updated: 2023/02/19 16:49:37 by alabdull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include "Libft/libft.h"

int		check_path(char **env);
char	*get_path(char *av, char **env);
void	pipex(char **av, char **env);
void	child_process(int *end, char **av, char **env);
void	parent_process(int *end, char **av, char **env);
void	fd_error(int fd, int *end);
void	execve_error(char **cmd);
void	arg_error(int exit_1);
void	free1(char **p);
void	free2(char **p1, char **p2);

#endif