#include "pipex.h"

void	create_pipe(int *pipe_fd)
{
	if (pipe(pipe_fd) == -1)
		perror_and_exit("pipe");
}
