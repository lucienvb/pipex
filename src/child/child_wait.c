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

void	child_wait(t_pipe *pipe)
{
	int	i;

	i = pipe->child_count;
	while (i)
	{
		wait(NULL);
		i--;
	}
}
