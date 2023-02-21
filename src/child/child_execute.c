#include "pipex.h"

static void	execute_first_child(t_pipe *pipe, int *pipe_fd)
{
	close(pipe_fd[0]);
//	ft_printf("kom ik in execute first child?\n");
	execute_cmd_and_write(pipe, pipe_fd);
	close(pipe_fd[1]);
}

static void	execute_middle_child(t_pipe *pipe, int *pipe_fd)
{
	execute_cmd_and_write(pipe, pipe_fd);
	pipes_close(pipe_fd);
}

static void	execute_last_child(t_pipe *pipe, int *pipe_fd)
{
	close(pipe_fd[1]);
//	ft_printf("kom ik in execute last child?\n");
	execute_cmd_and_write(pipe, pipe_fd);
	close(pipe_fd[0]);
}

void	execute_child(t_pipe *pipe, int *pipe_fd)
{
	if (pipe->cmd_index == 2)
		execute_first_child(pipe, pipe_fd);
	else if (pipe->cmd_index == pipe->last_cmd_index)
		execute_last_child(pipe, pipe_fd);
	else
		execute_middle_child(pipe, pipe_fd);
}
