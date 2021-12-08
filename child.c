/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   child.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/07 18:29:09 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2021/12/08 21:30:50 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	read_child(int argc, char *argv[], int *fd)
{
	int			file_fd;
	char		*bin_com;
	char		*input[3];

	dup2(fd[READ], 1);
	input[0] = argv[0];
	input[1] = argv[4];
	input[2] = NULL;
	bin_com = ft_strjoin("/usr/bin/", argv[3]);
	execve(bin_com, input, 0);
	printf("ERROR\n");
	exit(-1);
}

void	write_child(int argc, char *argv[])
{
	char	*input[3];
	char	*bin_com;

	input[0] = argv[0];
	input[1] = argv[1];
	input[2] = NULL;
	bin_com = ft_strjoin("/bin/", argv[2]);
	execve(bin_com, input, 0);
	exit(-1);
}
