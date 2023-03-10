/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_path_and_argv.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/16 14:09:58 by lvan-bus      #+#    #+#                 */
/*   Updated: 2023/02/16 14:10:00 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// creates new_argv: array with 1) the command
// 2) the flags 3) the infile (only for the first command)
char	**init_path_and_argv(t_pipe *p, char **new_argv)
{
	int	cmd_path;

	new_argv = ft_split(p->argv[p->cmd_index], ' ');
	if (access(new_argv[0], F_OK | X_OK) == 0)
		p->path = new_argv[0];
	else
	{
		cmd_path = access_to_index(p->path_list, new_argv[0]);
		if (cmd_path == -1)
			error_message(p->argv[p->cmd_index], 127);
		p->path = strjoin_three(p->path_list[cmd_path], "/", new_argv[0]);
	}
	return (new_argv);
}
