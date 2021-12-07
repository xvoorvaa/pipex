/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   child.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/07 18:29:09 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2021/12/07 20:58:18 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_steps(int argc, char *argv[])
{
	int		i;
	char	**input;
	char	*bin_com;

	i = 0;
	input = malloc(sizeof(char) * argc - 1);
	if (!input)
		exit(-1);
	while (i < argc - 1)
	{
		input[i] = ft_strdup(argv[i + 1]);
		i++;
	}
	input[argc - 1] = NULL;
	bin_com = ft_strjoin("/bin/", argv[1]);
	execve(bin_com, input, 0);
}
