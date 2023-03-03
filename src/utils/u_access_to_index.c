/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   access_to_index.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/16 11:51:05 by lvan-bus      #+#    #+#                 */
/*   Updated: 2023/02/16 11:51:07 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// this function joins three string
char	*strjoin_three(char *s1, char *s2, char *s3)
{
	char	*join_two;
	char	*join_three;

	join_two = ft_strjoin(s1, s2);
	if (!join_two)
		error_message("strjoin_three fails", 0);
	join_three = ft_strjoin(join_two, s3);
	if (!join_three)
	{
		error_message("strjoin_three fails", 0);
		free(join_two);
	}
	free(join_two);
	return (join_three);
}

// this function checks if a given system call exists
// and if it's possible to execute it
int	access_to_index(char **path, char *system_call)
{
	int		i;
	char	*syst_call_to_path;

	i = 0;
	while (path[i])
	{
		syst_call_to_path = strjoin_three(path[i], "/", system_call);
		if (access(syst_call_to_path, F_OK | X_OK) == 0
			&& access(syst_call_to_path, X_OK) == 0)
		{
			free(syst_call_to_path);
			return (i);
		}
		free(syst_call_to_path);
		i++;
	}
	return (-1);
}
