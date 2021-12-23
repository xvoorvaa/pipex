/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   child.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/07 18:29:09 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2021/12/23 18:41:08 by xander        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	read_child(char *argv[], char *envp[], int *fd)
{
	int			fd_file;
	char		**input;
	char		*usr_func;

	usr_func = path_check(argv[3], find_dir(envp));
	input = ft_split(argv[3], ' ');
	if (usr_func == NULL || input == NULL)
		return (perror("NULL error"));
	fd_file = open(argv[4], O_WRONLY | O_CREAT, 0644);
	if (close(fd[WRITE]) < 0 || fd_file < 0)
		return (perror("unistd.h error"));
	if (dup2(fd[READ], STDIN_FILENO) < 0)
		return (perror("Dup2() error"));
	if (dup2(fd_file, STDOUT_FILENO) < 0)
		return (perror("Dup2() error"));
	if (close(fd[READ]) < 0)
		return (perror("Close() error"));
	if (close(fd_file) < 0)
		return (perror("Close() error"));
	execve(usr_func, input, envp);
	return (perror("Execve() error"));
}

void	write_child(char *argv[], char *envp[], int *fd)
{
	int		fd_file;
	char	**input;
	char	*usr_func;

	fd_file = open(argv[1], O_RDONLY);
	if (close(fd[READ]) < 0 || fd_file < 0)
		return (perror("unistd.h error"));
	usr_func = path_check(argv[2], find_dir(envp));
	input = ft_split(argv[2], ' ');
	if (usr_func == NULL || input == NULL)
		return (perror("NULL error"));
	if (dup2(fd[WRITE], STDOUT_FILENO) < 0)
		return (perror("Dup2() error"));
	if (dup2(fd_file, STDIN_FILENO) < 0)
		return (perror("Dup2() error"));
	if (close(fd[WRITE]) < 0)
		return (perror("Close() error"));
	if (close(fd_file) < 0)
		return (perror("Close() error"));
	execve(usr_func, input, envp);
	return (perror("Execve() error"));
}
