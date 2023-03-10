/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create_pipe.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/10 16:41:06 by lvan-bus      #+#    #+#                 */
/*   Updated: 2023/02/10 16:41:07 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// this function creates a pipe checks if it succeeds
void	pipe_create(int *fd)
{
	if (pipe(fd) == -1)
		error();
}
