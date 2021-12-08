/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/06 18:10:24 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2021/12/08 21:29:13 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
	fd[0] = read;
	fd[1] = write;
*/

void	start_pipe(int argc, char *argv[])
{
	static int	fd[2];
	pid_t		fork_id1;
	pid_t		fork_id2;
	int			file_fd;
	int			nbytes;
	char		test[12];

	pipe(fd);
	if (pipe(fd) < 0)
		exit (-1); 
	fork_id1 = fork();
	if (fork_id1 == 0)
	{
		close(fd[READ]);
		dup2(fd[WRITE], 1);
		write_child(argc, argv);
	}
	fork_id2 = fork();
	if (fork_id2 == 0)
	{
		read_child(argc, argv, fd);
		exit(0);
	}
	waitpid(fork_id1, NULL, 0);
	waitpid(fork_id2, NULL, 0);
	dup2(fd[READ], 0);
	file_fd = open(argv[4], O_WRONLY | O_CREAT, 0644);
	read(0, test, 12);
	write(file_fd, test, 12);
	close(fd[READ]);
	close(fd[WRITE]);
	close(file_fd);
}

int	main(int argc, char *argv[], char *envp[])
{
	if (argc < 4)
	{
		printf("ERROR\n");
		return (-1);
	}
	start_pipe(argc, argv);
	return (0);
}
