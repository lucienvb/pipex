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
	pid_t	*child;
	int		fd[2];
	int		i;

	child = malloc(p->child_count * sizeof(pid_t));
	if (!child)
		exit(EXIT_FAILURE);
	i = 0;
	status = 0;
	while (p->cmd_index <= p->last_cmd_index)
	{
		if (p->cmd_index != p->last_cmd_index)
			pipe_create(fd);
		child[i] = child_create();
		if (child[i] == 0)
			execute_child(p, fd);
		else if (child[i] != 0 && p->cmd_index != p->last_cmd_index
			&& !p->random)
			execute_parent(fd);
		i++;
		p->cmd_index++;
	}
	execute_parent_end(p, &status, child, fd);
	return (WEXITSTATUS(status));
}
