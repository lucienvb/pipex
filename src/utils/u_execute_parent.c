#include "pipex.h"

void	execute_parent(t_pipe *pipe, int *pipe_fd, int *status, pid_t *pid)
{
	remove_split(pipe->path_list);
	pipes_close(pipe_fd);
	child_wait(pipe, pid, status);
}