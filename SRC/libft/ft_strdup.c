/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/07 18:42:02 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2021/12/07 20:21:24 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex.h"

char	*ft_strdup(const char *str1)
{
	char	*str2;
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(str1);
	str2 = (char *)malloc(sizeof(char) * len + 1);
	if (!str2)
		return (NULL);
	while (i < len)
	{
		str2[i] = str1[i];
		i++;
	}
	str2[i] = 0;
	return (str2);
}
