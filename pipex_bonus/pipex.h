/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alabdull <@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 02:26:38 by alabdull          #+#    #+#             */
/*   Updated: 2023/12/10 20:58:27 by alabdull         ###   ########.fr       */
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
void	ft_pipe(char *av, char **env);
void	pipex(int ac, char **av, char **env);
int		open_file(char *file, int in_or_out);
void	ft_execve(char *av, char **env);
// void	child_process(int in_fd, int *end, char **av, char **env);
// void	parent_process(int out_fd, int *end, char **av, char **env);
void	fd_error(int fd, int *end);
void	execve_error(char **cmd);
void	arg_error(int exit_1);
void	free1(char **p);
void	free2(char **p1, char **p2);

#endif