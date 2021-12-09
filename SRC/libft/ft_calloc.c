/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/09 16:12:33 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2021/12/09 16:25:09 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex.h"

void	*ft_calloc(size_t nitems, size_t n)
{
	void	*result;
	size_t	total;

	total = nitems * n;
	if (nitems == 0 || n == 0)
	{
		n = 1;
		nitems = 1;
	}
	result = malloc(n * nitems);
	if (!result)
		return (NULL);
	ft_bzero(result, total);
	return (result);
}
