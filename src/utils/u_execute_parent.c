#include "pipex.h"

void	execute_parent(int *pipe_fd)
{
	close(pipe_fd[1]);
	if (dup2(pipe_fd[0], STDIN_FILENO) == -1)
		perror_and_exit("dup2");
	close(pipe_fd[0]);
}

// need to check if it is necessary to close pipe_fd here
void	execute_parent_end(t_pipe *pipe, int *pipe_fd, int *status, pid_t *pid)
{
	(void)pipe_fd;
	remove_split(pipe->path_list);
//	pipes_close(pipe_fd);
	child_wait(pipe, pid, status);
}