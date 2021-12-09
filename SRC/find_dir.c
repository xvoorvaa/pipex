/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_dir.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/09 16:06:33 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2021/12/09 17:26:27 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	**find_dir(char *envp[])
{
	char	**path;

	path = ft_split(envp[6], ':');
	return (path);
}

char	*path_check(char *func, char **path)
{
	int		i;
	int		access_ok;
	char	*joined_path;

	i = 0;
	access_ok = -1;
	path[0] = ft_substr(path[0], 5, ft_strlen(path[0]) - 4);
	while (path[i] != NULL && access_ok != 0)
	{
		joined_path = ft_strjoin(path[i], "/");
		joined_path = ft_strjoin(joined_path, func);
		access_ok = access(joined_path, F_OK);
		i++;
	}
	return (joined_path);
}
