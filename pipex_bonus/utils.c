/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alabdull <@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 18:42:47 by alabdull          #+#    #+#             */
/*   Updated: 2023/12/11 18:00:31 by alabdull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_path(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			return (1);
		i++;
	}
	return (0);
}

int	find_path(char **env)
{
	int	i;

	i = 0;
	while (!ft_strnstr(env[i], "PATH=", 5))
		i++;
	return (i);
}

char	*get_path(char *av, char **env)
{
	char	*path;
	char	**full_path;
	char	**command;
	int		i;

	if (check_path(env) == 0)
		return (av);
	if (ft_strchr(av, '/'))
		return (av);
	i = find_path(env);
	full_path = ft_split(env[i] + 5, ':');
	command = ft_split(av, ' ');
	i = -1;
	while (full_path[++i])
	{
		path = ft_strjoin(ft_strjoin(full_path[i], "/"), command[0]);
		if (access(path, F_OK | X_OK) == 0)
		{
			free2(full_path, command);
			return (path);
		}
		free(path);
	}
	free2(full_path, command);
	return (NULL);
}
