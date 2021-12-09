/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bzero.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/09 16:12:55 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2021/12/09 16:12:59 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	ft_bzero(void *str, size_t n)
{
	unsigned long	i;
	char			*s;

	s = (char *) str;
	i = 0;
	while (n > i)
	{
		s[i] = 0;
		i++;
	}
}
