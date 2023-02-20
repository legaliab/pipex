/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alabdull <alabdull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 02:27:00 by alabdull          #+#    #+#             */
/*   Updated: 2023/02/19 18:47:39 by alabdull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex(char **av, char **env)
{
	int		end[2];
	pid_t	pid;

	if (pipe(end) == -1)
		exit(EOF);
	pid = fork();
	if (pid == -1)
		exit(EOF);
	if (pid == 0)
		child_process(end, av, env);
	wait(NULL);
	parent_process(end, av, env);
}

int	main(int ac, char **av, char **env)
{
	if (ac != 5)
		arg_error(EXIT_FAILURE);
	pipex(av, env);
}
