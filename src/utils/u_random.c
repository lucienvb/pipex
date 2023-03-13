/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   u_random.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/13 15:07:44 by lvan-bus      #+#    #+#                 */
/*   Updated: 2023/03/13 15:07:46 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// function that uses dup2 to write to the pipe
static void	init_to_pipe(int *fd)
{
	if (dup2(fd[PIPE_WRITE_INDEX], STDOUT_FILENO) == -1)
		error();
	close(fd[PIPE_WRITE_INDEX]);
}

// function that uses dup2 to write to the outfile
static void	init_to_outfile(t_pipe *p, int *fd)
{
	(void)fd;
	close(fd[PIPE_WRITE_INDEX]);
	if (dup2(p->outfile, STDOUT_FILENO) == -1)
		error();
	close(p->outfile);
}

static void	init_infile(t_pipe *p, int *fd)
{
	if (p->cmd_index == FIRST_CMD)
	{
		close(fd[PIPE_READ_INDEX]);
	}
	else
	{
		if (dup2(fd[PIPE_READ_INDEX], STDIN_FILENO) == -1)
			error();
		close(fd[PIPE_READ_INDEX]);
	}
}

// function that initializes which location to write to
void	init_random(t_pipe *p, int *fd)
{
	init_infile(p, fd);
	if (p->cmd_index != p->last_cmd_index)
		init_to_pipe(fd);
	else
		init_to_outfile(p, fd);
}
