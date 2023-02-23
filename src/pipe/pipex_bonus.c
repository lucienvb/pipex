#include "pipex.h"

//int	pipex_bonus(t_pipe *pipe, pid_t *pid)
//{
//	int		status;
//	int 	pipe_fd[2];
//	pid_t	child;
//
//	pid = get_pid(pipe, pid);
//	ft_bzero(pid, sizeof(pid_t) * FD_SIZE);
//	status = 0;
//	while (pipe->cmd_index != pipe->last_cmd_index)
//	{
//		pipe_create(pipe_fd);
//		child = child_create(child);
//		if (child == 0)
//			execute_child(pipe, pipe_fd);
//		else
//			execute_parent(pipe, pipe_fd, &status, pid);
//		pipe->cmd_index++;
//	}
////	free(pid);
//	return (WEXITSTATUS(status));
//}