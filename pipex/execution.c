/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alabdull <alabdull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 02:41:15 by alabdull          #+#    #+#             */
/*   Updated: 2023/02/19 14:13:14 by alabdull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_execve(char *av, char **env)
{
	char	**cmd;
	char	*path;

	path = NULL;
	cmd = ft_split(av, ' ');
	if (cmd[0])
		path = get_path(cmd[0], env);
	if (path)
	{
		if (execve(path, cmd, env) == -1)
			execve_error(cmd);
	}
	else
		execve_error(cmd);
}

void	child_process(int *end, char **av, char **env)
{
	int		fd;

	fd = open(av[1], O_RDONLY, 0777);
	if (fd == -1)
		fd_error(fd, end);
	dup2(fd, STDIN_FILENO);
	dup2(end[1], STDOUT_FILENO);
	close(end[0]);
	ft_execve(av[2], env);
}

void	parent_process(int *end, char **av, char **env)
{
	int		fd;

	fd = open(av[4], O_CREAT | O_RDWR | O_TRUNC, 0777);
	if (fd == -1)
		fd_error(fd, end);
	dup2(fd, STDOUT_FILENO);
	dup2(end[0], STDIN_FILENO);
	close(end[1]);
	ft_execve(av[3], env);
}
