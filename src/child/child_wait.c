/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   wait_for_child.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/10 16:40:26 by lvan-bus      #+#    #+#                 */
/*   Updated: 2023/02/10 16:40:28 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_wait(t_pipe *p, pid_t *child, int *status)
{
	size_t	i;

	i = 0;
	while (i < p->child_count)
		waitpid(child[i++], status, 0);
}
