#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "./libft/libft.h"

static void	perror_and_exit(char *str)
{
	perror(str);
	exit(1);
}

static void	pipex(int a)
{
	int 	pipe_fd[2];
	pid_t	pid[2];

	if (pipe(pipe_fd) == -1)
		perror_and_exit("pipe");
	pid[0] = fork();
	if (pid[0] == -1)
		perror_and_exit("fork");

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
		pid[1] = fork();
		if (pid[1] == -1)
			perror_and_exit("fork");
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
			close(pipe_fd[0]);
			close(pipe_fd[1]);
			wait(NULL);
			wait(NULL);
			ft_printf("I am the parent process\n");
		}
	}
}

int main(int argc, char **argv)
{
	int 	a;

	if (argc != 2)
		return (0);
	a = ft_atoi(argv[1]);
	pipex(a);
	return (0);
}