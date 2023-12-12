/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alabdull <alabdull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 02:41:33 by alabdull          #+#    #+#             */
/*   Updated: 2023/02/19 14:05:42 by alabdull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	fd_error(int fd, int *end)
{
	perror("no such file or directory\n");
	close(fd);
	close(end[0]);
	close(end[1]);
	exit(EXIT_FAILURE);
}

void	execve_error(char **cmd)
{
	ft_putstr_fd("command not found: ", 2);
	ft_putendl_fd(cmd[0], 2);
	free1(cmd);
	exit(EXIT_SUCCESS);
}

void	arg_error(int exit_1)
{
	if (exit_1 == 1)
		perror("./pipex file1 cmd1 cmd2 file2\n");
	exit(EXIT_SUCCESS);
}
