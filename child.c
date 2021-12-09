/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   child.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/07 18:29:09 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2021/12/09 21:40:00 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	read_child(char *argv[], char *envp[], int *fd)
{
	int			fd_file;
	char		*input[2];
	char		*usr_func;
	char		**path_input;

	path_input = find_dir(envp);
	usr_func = path_check(argv[3], path_input);
	fd_file = open(argv[4], O_WRONLY | O_CREAT, 0644);
	dup2(fd[READ], STDIN_FILENO);
	dup2(fd_file, STDOUT_FILENO);
	close(fd[READ]);
	close(fd_file);
	input[0] = argv[3];
	input[1] = NULL;
	execve(usr_func, input, envp);
	exit(-1);
}

void	write_child(char *argv[], char *envp[], int *fd)
{
	int		fd_file;
	char	*input[2];
	char	*usr_func;
	char	**path_input;

	path_input = find_dir(envp);
	usr_func = path_check(argv[2], path_input);
	fd_file = open(argv[1], O_RDONLY);
	dup2(fd[WRITE], STDOUT_FILENO);
	dup2(fd_file, STDIN_FILENO);
	close(fd[WRITE]);
	close(fd_file);
	input[0] = argv[2];
	input[1] = NULL;
	execve(usr_func, input, envp);
	exit(-1);
}
