/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/06 18:10:24 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2021/12/07 20:48:02 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#define READ 0
#define WRITE 1

/*
	fd[0] = read;
	fd[1] = write;
*/

void	start_pipe(int argc, char *argv[])
{
	static int	fd[2];
	int			fork_id;

	pipe(fd);
	if (pipe(fd) < 0)
		exit (-1);
	fork_id = fork();
	if (fork_id == 0)
	{
		close(fd[READ]);
		child_steps(argc, argv);
		close(fd[WRITE]);
	}
	else
	{
		close(fd[WRITE]);
		printf("HOI 42\n");
		close(fd[READ]);
	}
}

int main(int argc, char *argv[], char *envp[])
{
	start_pipe(argc, argv);
	return (0);
}
