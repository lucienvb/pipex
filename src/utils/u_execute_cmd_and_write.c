/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   execute_cmd_and_write.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/16 14:10:08 by lvan-bus      #+#    #+#                 */
/*   Updated: 2023/02/16 14:10:09 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// free remaining function
static void	free_rem(char **new_argv, t_pipe *pipe)
{
	if (new_argv)
		remove_split(new_argv);
	if (pipe->path_list)
		remove_split(pipe->path_list);
	if (pipe->path)
		free(pipe->path);
}

int	execute_cmd_and_write(t_pipe *pipe, int *pipe_fd)
{
	char	**new_argv;

	init_in_and_outfile(pipe, pipe_fd);
	new_argv = NULL;
	new_argv = init_path_and_argv(pipe, new_argv);
//	ft_array_print(new_argv);
//	ft_printf("path: %s\n", pipe->path);
	if (execve(pipe->path, new_argv, pipe->envp) == -1)
	{
		free_rem(new_argv, pipe);
		perror_and_exit("execve");
	}
//	ft_printf("en hier4\n");
	free_rem(new_argv, pipe);
	return (0);
}
