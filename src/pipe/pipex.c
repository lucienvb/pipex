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

static void	execute_child(t_pipe *pipe, int *pipe_fd)
{
	if (pipe->cmd_index == 2)
		execute_first_child(pipe, pipe_fd);
	else
		execute_last_child(pipe, pipe_fd);
}

static void	execute_parent(t_pipe *pipe, int *pipe_fd, int *status, pid_t *pid)
{
	remove_split(pipe->path_list);
	pipes_close(pipe_fd);
	child_wait(pipe, pid, status);
}

static pid_t	*get_pid(t_pipe *pipe, pid_t *pid)
{
	int	count;

	count = pipe->child_count;
	pid = malloc((count + 1) * sizeof(pid_t));
	if (!pid)
		perror_and_exit("pid memory allocation failed\n");
	return (pid);
}

static int	*get_pipe_fd(t_pipe *pipe, int *pipe_fd)
{
	int	count;

	count = pipe->child_count;
	pipe_fd = malloc((count + 1) * sizeof(int));
	if (!pipe_fd)
		perror_and_exit("pid memory allocation failed\n");
	return (pipe_fd);
}

// In this function two child processes are created that
// communicate via a pipe.
int	pipex(t_pipe *pipe, pid_t *pid, int *pipe_fd)
{
	int		status;

	pid = get_pid(pipe, pid);
	ft_bzero(pid, sizeof(pid_t) * FD_SIZE);
	pipe_fd = get_pipe_fd(pipe, pipe_fd);
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
	free(pipe_fd);
	return (WEXITSTATUS(status));
}

//int	pipex_bonus(t_pipe *pipe)
//{
//	pid_t	pid[FD_SIZE];
//	int		pipe_fd[pipe->child_count];
//	int		status;
//
//	status = 0;
//	ft_bzero(pid, sizeof(pid_t) * FD_SIZE);
//	pipe_create(pipe_fd);
//	pid[0] = child_create(pid[0]);
//	if (pid[0] != 0)
//	{
//		pipe->cmd_index++;
//		pid[1] = child_create(pid[1]);
//	}
//	if (pid[0] == 0 || pid[1] == 0)
//		execute_child(pipe, pipe_fd);
//	else
//		execute_parent(pipe, pipe_fd, &status, pid);
//	return (WEXITSTATUS(status));
//}
