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
	close(fd[1]);
	if (dup2(fd[0], STDIN_FILENO) == -1)
		error();
	close(fd[0]);
}

// this function frees the path_list variable and waits for
// the child processes and saves the status on the status address
void	execute_parent_end(t_pipe *p, int *status, pid_t *child)
{
	close(p->outfile);
	remove_split(p->path_list);
	child_wait(p, child, status);
}
