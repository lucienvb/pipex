#include "pipex.h"
static void	free_rem(char **new_argv, t_pipe *pipe)
{
	if (new_argv)
		remove_split(new_argv);
	if (pipe->path_list)
		remove_split(pipe->path_list);
	if (pipe->path)
		free(pipe->path);
}

int	execute_child(t_pipe *pipe, int *pipe_fd)
{
	char	**new_argv;

	init_in_and_outfile(pipe, pipe_fd);
	new_argv = NULL;
	new_argv = init_path_and_argv(pipe, new_argv);
	if (execve(pipe->path, new_argv, pipe->envp) == -1)
	{
		free_rem(new_argv, pipe);
		perror_and_exit("execve");
	}
	free_rem(new_argv, pipe);
	return (0);
}