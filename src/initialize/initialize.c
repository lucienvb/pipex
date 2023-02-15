#include "pipex.h"

bool	initialize(t_pipe *data, int argc, char **argv, char **envp)
{
//	(void)argc;
//	(void)argv;
//	if (!p_input_parsing(argc, argv))
//		return (false);
	data->path_list = split_path(envp);
	data->argv = argv;
	data->end = argc - 1;
	data->cmd_index = 2;
//	if (data->path == 0)
//		return (false);
	return (true);
}
