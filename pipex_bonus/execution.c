/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alabdull <@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 02:41:15 by alabdull          #+#    #+#             */
/*   Updated: 2023/12/12 21:18:05 by alabdull         ###   ########.fr       */
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

int	open_file(char *file, int in_or_out)
{
	int	fd;

	if (in_or_out == 0)
		fd = open(file, O_RDONLY, 0777);
	if (in_or_out == 1)
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (in_or_out == 2)
		fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0777);
	if (fd == -1)
		exit(0);
	return (fd);
}
