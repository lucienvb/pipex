/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   close_pipes.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/10 16:40:56 by lvan-bus      #+#    #+#                 */
/*   Updated: 2023/02/10 16:40:57 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// this function closes both ends of a pipe
void	pipes_close(int *fd)
{
	close(fd[0]);
	close(fd[1]);
}
