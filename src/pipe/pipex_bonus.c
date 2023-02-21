#include "pipex.h"

int	pipex_bonus(t_pipe *pipe, pid_t *pid)
{
	int		status;
	int 	pipe_fd[2];
//	int 	pipe_fd_ex[2];
	size_t	i;

	pid = get_pid(pipe, pid);
	ft_bzero(pid, sizeof(pid_t) * FD_SIZE);
	status = 0;
	i = 0;
	while (i < (pipe->child_count - 1))
	{
//		if (i % 2 == 0)
			pipe_create(pipe_fd);
//		else
//			pipe_create(pipe_fd_ex);
		pid[i] = child_create(pid[i]);
		if (pid[i] == 0)
			break ;
		i++;
		pipe->cmd_index += i;
	}
	if (pid[i] == 0)
		execute_child(pipe, pipe_fd);
	else
		execute_parent(pipe, pipe_fd, &status, pid);
	free(pid);
	return (WEXITSTATUS(status));
}