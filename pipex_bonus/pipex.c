/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alabdull <@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 02:27:00 by alabdull          #+#    #+#             */
/*   Updated: 2023/12/12 21:25:02 by alabdull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strcmp(char *s1, char *s2)
{
	int i = 0;
	while (s1[i] && s1[i] == s2[i])
		++i;
	return (s1[i] - s2[i]);
}

void	here_doc_in(char **av, int *end)
{
	char	*ret;

	close(end[0]);
	while (1)
	{
		ret = get_next_line(0);
		if (ft_strncmp(ret, av[2], ft_strlen(av[2])) == 0)
		{
			free(ret);
			exit(0);
		}
		ft_putstr_fd(ret, end[1]);
		free(ret);
	}
}

void	here_doc(char **av)
{
	int	end[2];
	int status;
	pid_t pid;

	if (pipe(end) == -1)
		exit(0);
	pid = fork();
	if (pid == -1)
		exit(0);
	if (pid == 0)
		here_doc_in(av, end);
	else
	{
		close(end[1]);
		dup2(end[0], STDIN_FILENO);
		waitpid(pid, &status, 0);
	}
}

void	ft_pipe(char *av, char **env)
{
	pid_t	pid;
	int		status;
	int		end[2];

	if (pipe(end) == -1)
		exit(0);
	pid = fork();
	if (pid == -1)
		exit(0);
	if (!pid)
	{
		close(end[0]);
		dup2(end[1], STDOUT_FILENO);
		ft_execve(av, env);
	}
	else
	{
		close(end[1]);
		dup2(end[0], STDIN_FILENO);
	}
	waitpid(pid, &status, 0);
}

void	pipex(int ac, char **av, char **env)
{
	int	i;
	int	fd_in;
	int	fd_out;

	if (ac < 5)
		arg_error(EXIT_FAILURE);
	if (ft_strcmp(av[1], "here_doc") == 0)
	{
		if (ac < 6)
			arg_error(EXIT_FAILURE);
		i = 3;
		fd_out = open_file(av[ac - 1], 2);
		here_doc(av);
	}
	else
	{
		i = 2;
		fd_in = open_file(av[1], 0);
		fd_out = open_file(av[ac - 1], 1);
		dup2(fd_in, 0);
		while (i < ac - 2)
			ft_pipe(av[i++], env);
		dup2(fd_out, 1);
		ft_execve(av[ac - 2], env);
	}
}

int	main(int ac, char **av, char **env)
{
	pipex(ac, av, env);
}
