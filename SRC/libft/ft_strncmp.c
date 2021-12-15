/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: xander <xander@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/15 13:33:44 by xander        #+#    #+#                 */
/*   Updated: 2021/12/15 13:36:00 by xander        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((str1[i] != 0 && str2[i] != 0) && (str1[i] == str2[i] && n - 1 > i))
		i++;
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}
