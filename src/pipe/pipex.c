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
	pid_t	pid[FD_SIZE];
	int		pipe_fd[pipe->child_count];
	int		status;

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

int	pipex_bonus(t_pipe *pipe)
{
	pid_t	pid[pipe->child_count];
	int		pipe_fd[pipe->child_count];
	int		status;
	size_t	i;

	ft_bzero(pid, sizeof(pid_t) * FD_SIZE);
	i = 0;
	while (i < (pipe->child_count - 1))
	{
		pipe->cmd_index += i;
		pipe_create(pipe_fd);
		pid[i] = child_create(pid[i]);
		if (pid[i] == 0)
			break ;
		i++;
	}
	if (pipe->child_count == 2 && i == 1)
		i--;
	if (pid[i] == 0)
		execute_first_child(pipe, pipe_fd);
	else
	{
		if (pipe->child_count == 2)
			i++;
		// the minus one below shouldn't be necessary
		pipe->cmd_index += (i - 1);
//		pipe->cmd_index += i;
		pid[i] = child_create(pid[i]);
		if (pid[i] == 0)
			execute_last_child(pipe, pipe_fd);
		else
		{
			remove_split(pipe->path_list);
			pipes_close(pipe_fd);
			child_wait(pipe, pid, &status);
		}
	}
	return (WEXITSTATUS(status));
}
