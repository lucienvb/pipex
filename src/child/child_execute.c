#include "pipex.h"

static void	free_rem(char **new_argv, t_pipe *p)
{
	if (new_argv)
		remove_split(new_argv);
	if (p->path_list)
		remove_split(p->path_list);
	if (p->path)
		free(p->path);
}

int	execute_child(t_pipe *p, int *fd)
{
	char	**new_argv;

	init_in_and_outfile(p, fd);
	new_argv = NULL;
	new_argv = init_path_and_argv(p, new_argv);
	if (execve(p->path, new_argv, p->envp) == -1)
	{
		free_rem(new_argv, p);
		perror_and_exit("execve");
	}
	free_rem(new_argv, p);
	return (0);
}