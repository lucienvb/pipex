#include "pipex.h"

pid_t	create_child(pid_t pid)
{
	pid = fork();
	if (pid == -1)
		perror_and_exit("fork");
	return (pid);
}
