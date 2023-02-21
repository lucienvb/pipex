#include "pipex.h"

pid_t	*get_pid(t_pipe *pipe, pid_t *pid)
{
	int	count;

	count = pipe->child_count;
	pid = malloc((count + 1) * sizeof(pid_t));
	if (!pid)
		perror_and_exit("pid memory allocation failed\n");
	return (pid);
}
