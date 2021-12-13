/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/02 13:55:49 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2021/12/13 19:12:10 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <fcntl.h>
# define READ 0
# define WRITE 1

/*
	0 = false
	1 = true
*/

/*
	LIBFT
*/

size_t	ft_strlen(char const *str);

char	*ft_strjoin(char const *s1, char const *s2);

char	*ft_strdup(const char *str1);

int		ft_strchr(const char *str, int c);

void	ft_bzero(void *str, size_t n);

void	*ft_calloc(size_t nitems, size_t n);

char	**ft_split(char const *s, char c);

char	*ft_substr(char const *str, unsigned int start, size_t len);

/*
	PIPE'N - ( ͡° ͜ʖ ͡°)
*/

void	write_child(char *argv[], char *envp[], int *fd);

void	read_child(char *argv[], char *envp[], int *fd);

void	start_pipe(char *argv[], char *envp[]);

int		main(int argc, char *argv[], char *envp[]);

void	error_management(int error);

/*
	UTILS
*/

char	**find_dir(char *envp[]);

char	*path_check(char *func, char **path);

#endif
