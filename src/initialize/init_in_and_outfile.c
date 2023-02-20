/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cmd_to_outfile.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/10 16:41:32 by lvan-bus      #+#    #+#                 */
/*   Updated: 2023/02/16 14:09:35 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	init_to_pipe(int *pipe_fd)
{
	if (dup2(pipe_fd[1], STDOUT_FILENO) == -1)
		perror_and_exit("dup2");
}

static void	init_from_and_to_pipe(int *pipe_fd)
{
	if (dup2(pipe_fd[0], STDIN_FILENO) == -1)
		perror_and_exit("dup2");
	if (dup2(pipe_fd[1], STDOUT_FILENO) == -1)
		perror_and_exit("dup2");
}

// opens a utils (argv[3]) to write to with the dup2 function
// the utils is in this case the outfile
static void	init_to_outfile(t_pipe *pipe, int *pipe_fd)
{
	int	i;
	int	outfd;

	i = pipe->end;
	close(pipe_fd[1]);
	outfd = open(pipe->argv[i], O_CREAT | O_TRUNC | O_WRONLY);
	if (outfd == -1)
		perror_and_exit("open");
	if (dup2(pipe_fd[0], STDIN_FILENO) == -1)
		perror_and_exit("dup2");
	if (dup2(outfd, STDOUT_FILENO) == -1)
		perror_and_exit("dup2");
}

void	init_in_and_outfile(t_pipe *pipe, int *pipe_fd)
{
//	ft_printf("cmd_index: %i\n", pipe->cmd_index);
	if (pipe->cmd_index == pipe->last_cmd_index)
	{
		ft_printf("kom ik hier? 1\n");
		init_to_outfile(pipe, pipe_fd);
	}
	else if (pipe->cmd_index == 2) {
		ft_printf("kom ik hier? 2\n");
		init_to_pipe(pipe_fd);
	}
	else {
		ft_printf("kom ik hier? 3\n");
		init_from_and_to_pipe(pipe_fd);
	}
}
