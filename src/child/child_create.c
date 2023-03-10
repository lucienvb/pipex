/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create_child.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/10 16:40:15 by lvan-bus      #+#    #+#                 */
/*   Updated: 2023/02/10 16:40:16 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

pid_t	child_create(void)
{
	pid_t	child;

	child = fork();
	if (child == -1)
		error();
	return (child);
}
