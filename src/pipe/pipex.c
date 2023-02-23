/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/10 16:41:47 by lvan-bus      #+#    #+#                 */
/*   Updated: 2023/02/10 16:41:49 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// In this function two child processes are created that
// communicate via a pipe.
int	pipex(t_pipe *pipe)
{
	int		status;
	int		pipe_fd[2];
	pid_t	child;

	if (dup2(pipe->infile, STDIN_FILENO) == -1)
		perror_and_exit("dup2");
	child = 0;
	status = 0;
	while (pipe->cmd_index <= pipe->last_cmd_index)
	{
		if (pipe->cmd_index != pipe->last_cmd_index)
			pipe_create(pipe_fd);
		child = child_create(child);
		if (child == 0)
			execute_child(pipe, pipe_fd);
		else if (child != 0 && pipe->cmd_index != pipe->last_cmd_index)
			execute_parent(pipe_fd);
		pipe->cmd_index++;
	}
	if (child != 0)
		execute_parent_end(pipe, pipe_fd, &status, &child);
	return (WEXITSTATUS(status));
}
