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

static void	execute_first_child(t_pipe *pipe, int *pipe_fd)
{
	close(pipe_fd[0]);
	execute_cmd_and_write(pipe, pipe_fd);
	close(pipe_fd[1]);
}

static void	execute_last_child(t_pipe *pipe, int *pipe_fd)
{
	close(pipe_fd[1]);
	execute_cmd_and_write(pipe, pipe_fd);
	close(pipe_fd[0]);
}

// In this function two child processes are created that
// communicate via a pipe.
int	pipex(t_pipe *pipe)
{
	pid_t	pid[FD_SIZE];
	int		pipe_fd[2];
	int 	status;

	ft_bzero(pid, sizeof(pid_t) * FD_SIZE);
	pipe_create(pipe_fd);
	pid[0] = child_create(pid[0]);
	if (pid[0] == 0)
		execute_first_child(pipe, pipe_fd);
	else
	{
		pipe->cmd_index++;
		pid[1] = child_create(pid[1]);
		if (pid[1] == 0)
			execute_last_child(pipe, pipe_fd);
		else
		{
			remove_split(pipe->path_list);
			pipes_close(pipe_fd);
//			child_wait(pipe);
			waitpid(pid[0], &status, 0);
			waitpid(pid[1], &status, 0);
		}
	}
	return (WEXITSTATUS(status));
}
