/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/10 16:41:47 by lvan-bus      #+#    #+#                 */
/*   Updated: 2023/02/10 16:41:49 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// pipex function wherein two or more child processes are created
// that communicate with each other through pipes
int	pipex(t_pipe *p)
{
	int		status;
	int		fd[2];
	pid_t	*child;
	int 	i;

	child = malloc(p->child_count * sizeof(pid_t));
	if (!child)
		exit(EXIT_FAILURE);
	i = 0;
	if (dup2(p->infile, STDIN_FILENO) == -1)
		exit(4);
	close(p->infile);
	status = 0;
	while (p->cmd_index <= p->last_cmd_index)
	{
		if (p->cmd_index != p->last_cmd_index)
			pipe_create(fd);
		child[i] = child_create();
		if (child[i] == 0)
			execute_child(p, fd);
		else if (child[i] != 0 && p->cmd_index != p->last_cmd_index)
			execute_parent(fd);
		i++;
		p->cmd_index++;
	}
	close(fd[PIPE_READ_INDEX]);
	close(fd[PIPE_WRITE_INDEX]);
	if (child != 0)
		execute_parent_end(p, &status, child);
	unlink("no_infile");
	free(child);
	return (WEXITSTATUS(status));
}
