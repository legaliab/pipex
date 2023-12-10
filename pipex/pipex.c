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
	pid_t	pid_in;
	pid_t	pid_out;
	int		status;

	if (pipe(end) == -1)
		exit(EOF);
	pid_in = fork();
	if (pid_in == -1)
		exit(EOF);
	if (pid_in == 0)
		child_process(end, av, env);
	pid_out = fork();
	if (pid_out == -1)
		exit(EOF);
	if (pid_out == 0)
		parent_process(end, av, env);
	waitpid(pid_in, &status, 0);
	waitpid(pid_in, &status, 0);
}

int	main(int ac, char **av, char **env)
{
	int i = 0;
	if (ac != 5)
		arg_error(EXIT_FAILURE);
	pipex(av, env);
}
