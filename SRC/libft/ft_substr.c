/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/09 16:28:05 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2021/12/09 16:28:16 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex.h"

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	size_t			i;
	size_t			slen;
	char			*substr;

	i = 0;
	if (str == NULL)
		return (NULL);
	slen = ft_strlen(str);
	substr = malloc(sizeof(char) * len + 1);
	if (!substr)
		return (NULL);
	while (str[i] && i < len && slen > start)
	{
		substr[i] = str[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
