/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   execute_cmd_and_write.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/16 14:10:08 by lvan-bus      #+#    #+#                 */
/*   Updated: 2023/02/16 14:10:09 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	execute_cmd_and_write(t_pipe *data, int *pipe_fd)
{
	char	**new_argv;

	init_in_and_outfile(data, pipe_fd);
	new_argv = NULL;
	new_argv = init_path_and_argv(data, new_argv);
	if (execve(data->path, new_argv, NULL) == -1)
		perror_and_exit("execve");
	return (0);
}
