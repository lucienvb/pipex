#include "pipex.h"

void	execute_first_child(t_pipe *pipe, int *pipe_fd)
{
	close(pipe_fd[0]);
//	ft_printf("kom ik in execute first child?\n");
	execute_cmd_and_write(pipe, pipe_fd);
	close(pipe_fd[1]);
}

void	execute_middle_child(t_pipe *pipe, int *pipe_fd)
{
	execute_cmd_and_write(pipe, pipe_fd);
	pipes_close(pipe_fd);
}

void	execute_last_child(t_pipe *pipe, int *pipe_fd)
{
	close(pipe_fd[1]);
//	ft_printf("kom ik in execute last child?\n");
	execute_cmd_and_write(pipe, pipe_fd);
	close(pipe_fd[0]);
}
