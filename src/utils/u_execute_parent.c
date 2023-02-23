#include "pipex.h"

// this function closes the write end of the pipe,
// reads from the pipe and then closes the read end
void	execute_parent(int *fd)
{
	close(fd[1]);
	if (dup2(fd[0], STDIN_FILENO) == -1)
		perror_and_exit("dup2");
	close(fd[0]);
}

// need to check if it is necessary to close fd here

// this function frees the path_list variable and waits for
// the child processes and saves the status on the status address
void	execute_parent_end(t_pipe *p, int *fd, int *status, pid_t *child)
{
	(void)fd;
	remove_split(p->path_list);
//	pipes_close(fd);
	child_wait(p, child, status);
}