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

static void	execute_first_child(t_pipe *data, int *pipe_fd)
{
	close(pipe_fd[0]);
	execute_cmd_and_write(data, pipe_fd);
	close(pipe_fd[1]);
}

static void	execute_last_child(t_pipe *data, int *pipe_fd)
{
	close(pipe_fd[1]);
	execute_cmd_and_write(data, pipe_fd);
	close(pipe_fd[0]);
}

// In this function two child processes are created that
// communicate via a pipe.
void	pipex(t_pipe *data)
{
	int		pipe_fd[2];
	pid_t	pid[2];

	create_pipe(pipe_fd);
	pid[0] = create_child(pid[0]);
	if (pid[0] == 0)
		execute_first_child(data, pipe_fd);
	else
	{
		data->cmd_index++;
		pid[1] = create_child(pid[1]);
		if (pid[1] == 0)
			execute_last_child(data, pipe_fd);
		else
		{
			close_pipes(pipe_fd);
			wait_for_child();
		}
	}
}
