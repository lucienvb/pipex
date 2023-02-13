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

pid_t	create_child(pid_t pid)
{
	pid = fork();
	if (pid == -1)
		perror_and_exit("fork");
	return (pid);
}
