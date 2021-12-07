/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/06 18:10:24 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2021/12/07 16:27:50 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#define READ 0
#define WRITE 1

/*
	fd[0] = read;
	fd[1] = write;
*/

void	start_pipe(char *argv[])
{
	int			fork_id;
	static int	fd[2];
	char 		test[4];

	pipe(fd);
	if (pipe(fd) < 0)
		exit (-1);
	fork_id = fork();
	if (fork_id == 0)
	{
		close(fd[READ]);
		execve("/bin/cat", argv, 0);
		write(fd[WRITE], argv[1], 3);
		close(fd[WRITE]);
	}
	else
	{
		close(fd[WRITE]);
		read(fd[READ], test, 4);
		close(fd[READ]);
		printf("READ: %s\n", test);
	}
}

int main(int argc, char *argv[], char *envp[])
{
	start_pipe(argv);
	return (0);
}
