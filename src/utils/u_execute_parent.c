/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   u_execute_parent.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/23 16:59:13 by lvan-bus      #+#    #+#                 */
/*   Updated: 2023/02/23 16:59:14 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// this function closes the write end of the pipe,
// reads from the pipe and then closes the read end
void	execute_parent(int *fd)
{
	close(fd[PIPE_WRITE_INDEX]);
	if (dup2(fd[PIPE_READ_INDEX], STDIN_FILENO) == -1)
		error();
	close(fd[PIPE_READ_INDEX]);
}

// this function frees the path_list variable and waits for
// the child processes and saves the status on the status address
void	execute_parent_end(t_pipe *p, int *status, pid_t *child, int *fd)
{
	if (p->random)
	{
		close(fd[PIPE_READ_INDEX]);
		close(fd[PIPE_WRITE_INDEX]);
	}
	child_wait(p, child, status);
	close(p->outfile);
	remove_split(p->path_list);
	unlink("no_infile");
	free(child);
}
