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

void	pipe_create(int *pipe_fd)
{
	if (pipe(pipe_fd) == -1)
		perror_and_exit("pipe");
}
