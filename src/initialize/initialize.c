/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initialize.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/16 11:50:36 by lvan-bus      #+#    #+#                 */
/*   Updated: 2023/02/16 11:50:38 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

bool	initialize(t_pipe *data, int argc, char **argv, char **envp)
{
	if (!p_input_parsing(argc, argv))
		return (false);
	data->path_list = split_path(envp);
	data->argv = argv;
	data->end = argc - 1;
	data->cmd_index = 2;
	data->last_cmd_index = argc - 2;
//	if (data->path == 0)
//		return (false);
	return (true);
}
