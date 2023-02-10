#include "pipex.h"

static void	execute_first_child(int *a, int *pipe_fd, char *mes)
{
	*a *= 2;
	write(pipe_fd[1], a, sizeof(*a));
	close_pipes(pipe_fd);
	ft_printf("'a' at the end of the %s child process: %i\n", mes, *a);
}

static void	execute_second_child(int *a, int *pipe_fd, char *mes)
{
	read(pipe_fd[0], a, sizeof(*a));
	close_pipes(pipe_fd);
	*a *= 2;
	ft_printf("'a' at the end of the %s child process: %i\n", mes, *a);
}

void	pipex(int a)
{
	int 	pipe_fd[2];
	pid_t	pid[2];

	create_pipe(pipe_fd);
	pid[0] = create_child(pid[0]);
	if (pid[0] == 0)
		execute_first_child(&a, pipe_fd, FIRST);
	else
	{
		pid[1] = create_child(pid[1]);
		if (pid[1] == 0)
			execute_second_child(&a, pipe_fd, SECOND);
		else
		{
			close_pipes(pipe_fd);
			wait_for_child();
			ft_printf("I am the parent process\n");
		}
	}
}
