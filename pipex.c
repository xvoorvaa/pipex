/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/06 18:10:24 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2021/12/12 16:39:06 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <errno.h>

/*
	fd[0] = read;
	fd[1] = write;
*/

void	start_pipe(char *argv[], char *envp[])
{
	static int	fd[2];
	pid_t		fork_id1;
	pid_t		fork_id2;

	pipe(fd);
	if (pipe(fd) < 0)
		exit (-1);
	fork_id1 = fork();
	if (fork_id1 == 0)
	{
		close(fd[READ]);
		write_child(argv, envp, fd);
	}
	fork_id2 = fork();
	if (fork_id2 == 0)
	{
		close(fd[WRITE]);
		read_child(argv, envp, fd);
	}
	waitpid(fork_id1, NULL, 0);
	close(fd[READ]);
	close(fd[WRITE]);
}

int	main(int argc, char *argv[], char *envp[])
{
	if (argc < 5 || argc > 5)
	{
		perror("Invalid argument");
		return (-1);
	}
	start_pipe(argv, envp);
	return (0);
}
