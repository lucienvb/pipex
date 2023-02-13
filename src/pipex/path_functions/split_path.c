/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   split_path.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/13 13:40:57 by lvan-bus      #+#    #+#                 */
/*   Updated: 2023/02/13 13:40:58 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*find_path_in_env(char **envp)
{
	int		i;
	char	*tmp;

	i = 0;
	while (envp[i])
	{
		tmp = ft_strnstr(envp[i], "PATH=", 5);
		if (tmp)
			break ;
		i++;
	}
	if (tmp == NULL)
		return (NULL);
	return (&tmp[5]);
}

char	**split_path(char **envp)
{
	char	**split;
	char	*path;

	path = find_path_in_env(envp);
	split = ft_split(path, ':');
	return (split);
}
