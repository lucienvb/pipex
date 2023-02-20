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

static void	init_path_list(t_pipe *pipe, char **envp)
{
	pipe->path_list = split_path(envp);
	if (!pipe->path_list)
		perror_and_exit("error: path not found\n");
}

bool	initialize(t_pipe *pipe, int argc, char **argv, char **envp)
{
	if (!error_handling(argc, argv))
		return (false);
	init_path_list(pipe, envp);
	pipe->argv = argv;
	pipe->end = argc - 1;
	pipe->cmd_index = FIRST_CMD;
	pipe->last_cmd_index = argc - 2;
	pipe->child_count = argc - 3;
	return (true);
}

bool	initialize_bonus(t_pipe *pipe, int argc, char **argv, char **envp)
{
	if (!error_handling_bonus(argc, argv))
		return (false);
	init_path_list(pipe, envp);
	pipe->argv = argv;
	pipe->end = argc - 1;
	pipe->cmd_index = FIRST_CMD;
	pipe->last_cmd_index = argc - 2;
	pipe->child_count = argc - 3;
	return (true);
}

