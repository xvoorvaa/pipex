/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_management.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/12 19:58:56 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2021/12/14 22:03:36 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	error_management(int error)
{
	if (error == -1)
		perror("Invalid argument");
	else if (error == -2)
		perror("Fork() Error");
	else if (error == -3)
		perror("Pipe() Error");
	else if (error == -4)
		perror("Execve() ERROR");
	else if (error == -5)
		perror("Dup2 ERROR");
	else if (error == -6)
		perror("Path ERROR");
	else if (error == -7)
		perror("Env ERROR");
	exit (error);
}
