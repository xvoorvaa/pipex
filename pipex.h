/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/02 13:55:49 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2021/12/07 20:21:51 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

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

/*
	PIPE'N - ( ͡° ͜ʖ ͡°)
*/

void	start_pipe(int argc, char *argv[]);

void	child_steps(int argc, char *argv[]);

int		main(int argc, char *argv[], char *envp[]);

#endif
