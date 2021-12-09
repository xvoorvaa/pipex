/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/09 16:11:44 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2021/12/09 16:11:56 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex.h"

void	*ft_freearray(char **s, int i)
{
	while (i > 0)
	{
		i--;
		free(s[i]);
	}
	free(s);
	return (NULL);
}

size_t	ft_countwords(const char *str, int c)
{
	int				state;
	unsigned int	counter;

	state = 0;
	counter = 0;
	while (*str)
	{
		if (*str == c)
			state = 0;
		else if (state == 0)
		{
			state = 1;
			counter++;
		}
		++str;
	}
	return (counter);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	size_t	i;
	size_t	pos;
	size_t	len;

	i = 0;
	len = 0;
	if (!s)
		return (NULL);
	str = (char **)ft_calloc(sizeof(char *), ft_countwords(s, c) + 1);
	if (!str)
		return (NULL);
	while (i < ft_countwords(s, c))
	{
		while (s[len] == c)
			len++;
		pos = len;
		while (s[len] && s[len] != c)
			len++;
		str[i] = ft_substr(s, pos, len - pos);
		if (str[i] == NULL)
			return (ft_freearray(str, i));
		i++;
	}
	return (str);
}
