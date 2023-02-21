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

/*static int	*get_pipe_fd(t_pipe *pipe, int *pipe_fd)
{
	int	count;

	count = pipe->child_count;
	pipe_fd = malloc((count + 1) * sizeof(int));
	if (!pipe_fd)
		perror_and_exit("pipe_fd memory allocation failed\n");
	return (pipe_fd);
}*/

// In this function two child processes are created that
// communicate via a pipe.
int	pipex(t_pipe *pipe, pid_t *pid)
{
	int		status;
	int		pipe_fd[2];

	pid = get_pid(pipe, pid);
	ft_bzero(pid, sizeof(pid_t) * FD_SIZE);
	status = 0;
	pipe_create(pipe_fd);
	pid[0] = child_create(pid[0]);
	if (pid[0] != 0)
	{
		pipe->cmd_index++;
		pid[1] = child_create(pid[1]);
	}
	if (pid[0] == 0 || pid[1] == 0)
		execute_child(pipe, pipe_fd);
	else
		execute_parent(pipe, pipe_fd, &status, pid);
	free(pid);
	return (WEXITSTATUS(status));
}
