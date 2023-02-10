#include "pipex.h"

static void	create_pipe(int *pipe_fd)
{
	if (pipe(pipe_fd) == -1)
		perror_and_exit("pipe");
}

static pid_t	create_child(pid_t pid)
{
	pid = fork();
	if (pid == -1)
		perror_and_exit("fork");
	return (pid);
}
//
//static void	child_process(int *a, int *pipe_fd, char *message, int child)
//{
//	if (!child)
//	{
//		*a *= 2;
//		close(pipe_fd[0]);
//		write(pipe_fd[1], &a, sizeof(a));
//		close(pipe_fd[1]);
//	}
//	else
//	{
//		close(pipe_fd[1]);
//		read(pipe_fd[0], &a, sizeof(a));
//		close(pipe_fd[0]);
//		*a *= 2;
//	}
//	ft_printf("%s %i\n", message, *a);
//}
//
static void	close_pipes(int *pipe_fd)
{
	close(pipe_fd[0]);
	close(pipe_fd[1]);
}

static void	wait_for_child(void)
{
	int	i;

	i = 2;
	while (i)
	{
		wait(NULL);
		i--;
	}
}

void	pipex(int a)
{
	int 	pipe_fd[2];
	pid_t	pid[2];

	create_pipe(pipe_fd);
	pid[0] = create_child(pid[0]);
	if (pid[0] == 0)
	{
		close(pipe_fd[0]);
		a *= 2;
		write(pipe_fd[1], &a, sizeof(a));
		close(pipe_fd[1]);
		ft_printf("'a' at the end of the first child process: %i\n", a);
	}
	else
	{
		pid[1] = create_child(pid[1]);
		if (pid[1] == 0)
		{
			close(pipe_fd[1]);
			read(pipe_fd[0], &a, sizeof(a));
			close(pipe_fd[0]);
			a *= 2;
			ft_printf("'a' at the end of the second child process: %i\n", a);
		}
		else
		{
			close_pipes(pipe_fd);
			wait_for_child();
			ft_printf("I am the parent process\n");
		}
	}
}
