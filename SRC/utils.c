/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/09 16:06:33 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2021/12/21 17:38:37 by xander        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	path_row(char *envp[])
{
	int		i;
	char	*path;

	i = 0;
	while (envp[i] != NULL)
	{
		if (envp[i][0] == 'P')
		{
			path = ft_substr(envp[i], 0, 4);
			if (ft_strncmp(path, "PATH", 4) == 0)
				return (i);
		}
		i++;
	}
	perror("ENV error");
	exit (errno);
}

char	**find_dir(char *envp[])
{
	int		i;
	char	**path;

	i = path_row(envp);
	path = ft_split(envp[i], ':');
	if (path == NULL)
		return (NULL);
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
	if (ft_strchr(func, ' ') == true)
		func = *ft_split(func, ' ');
	if (access(func, F_OK) == 0)
		return (func);
	while (path[i] != NULL && access_ok != 0)
	{
		joined_path = ft_strjoin(path[i], "/");
		joined_path = ft_strjoin(joined_path, func);
		access_ok = access(joined_path, F_OK);
		i++;
	}
	if (access_ok == -1)
		return (NULL);
	return (joined_path);
}
