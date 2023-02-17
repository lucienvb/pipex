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

char	*strjoin_three(char *s1, char *s2, char *s3)
{
	char	*join_three;

	join_three = ft_strjoin(s1, s2);
	if (!join_three)
		perror_and_exit("strjoin_three fails");
	join_three = ft_strjoin(join_three, s3);
	if (!join_three)
		perror_and_exit("strjoin_three fails");
	return (join_three);
}

int	access_to_index(char **path, char *system_call)
{
	int		i;
	char	*syst_call_to_path;

	i = 0;
	while (path[i])
	{
		syst_call_to_path = strjoin_three(path[i], "/", system_call);
		if (access(syst_call_to_path, F_OK) == 0
			&& access(syst_call_to_path, X_OK) == 0)
			return (i);
		i++;
	}
	return (-1);
}
