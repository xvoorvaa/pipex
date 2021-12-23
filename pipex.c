/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/06 18:10:24 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2021/12/23 18:41:00 by xander        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
	fd[0] = read;
	fd[1] = write;
*/

void	start_pipe(char *argv[], char *envp[])
{
	static int	fd[2];
	pid_t		fork_id1;
	pid_t		fork_id2;

	if (pipe(fd) < 0)
		return (perror("Pipe() error"));
	fork_id1 = fork();
	if (fork_id1 == 0)
	{
		write_child(argv, envp, fd);
		exit(errno);
	}
	fork_id2 = fork();
	if (fork_id2 == 0)
	{
		read_child(argv, envp, fd);
		exit(errno);
	}
	if (fork_id1 < 0 || fork_id2 < 0)
		return (perror("Fork() error"));
	if (close(fd[READ]) < 0)
		exit(errno);
	if (close(fd[WRITE]) < 0)
		exit(errno);
}

int	main(int argc, char *argv[], char *envp[])
{
	if (argc < 5 || argc > 5)
		return (EINVAL);
	start_pipe(argv, envp);
	return (errno);
}
