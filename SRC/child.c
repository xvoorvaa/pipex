/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   child.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/07 18:29:09 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2021/12/14 21:56:03 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	read_child(char *argv[], char *envp[], int *fd)
{
	int			fd_file;
	char		**input;
	char		*usr_func;

	close(fd[WRITE]);
	usr_func = path_check(argv[3], find_dir(envp));
	if (usr_func == NULL)
		error_management(-6);
	fd_file = open(argv[4], O_WRONLY | O_CREAT, 0644);
	input = ft_split(argv[3], ' ');
	dup2(fd[READ], STDIN_FILENO);
	dup2(fd_file, STDOUT_FILENO);
	close(fd[READ]);
	close(fd_file);
	execve(usr_func, input, envp);
	error_management(-4);
}

void	write_child(char *argv[], char *envp[], int *fd)
{
	int		fd_file;
	char	**input;
	char	*usr_func;

	close(fd[READ]);
	usr_func = path_check(argv[2], find_dir(envp));
	if (usr_func == NULL)
		error_management(-6);
	input = ft_split(argv[2], ' ');
	fd_file = open(argv[1], O_RDONLY);
	dup2(fd[WRITE], STDOUT_FILENO);
	dup2(fd_file, STDIN_FILENO);
	close(fd[WRITE]);
	close(fd_file);
	execve(usr_func, input, envp);
	error_management(-4);
}
