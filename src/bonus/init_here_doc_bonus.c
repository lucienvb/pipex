/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_here_doc_bonus.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/27 16:52:42 by lvan-bus      #+#    #+#                 */
/*   Updated: 2023/02/27 16:52:44 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_here_doc(t_pipe *p, int argc)
{
	p->infile = here_doc(p);
	p->child_count = argc - 4;
	p->cmd_index = FIRST_CMD_HD;
	p->here_doc = 1;
}
