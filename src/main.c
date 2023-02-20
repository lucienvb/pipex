/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/10 16:39:17 by lvan-bus      #+#    #+#                 */
/*   Updated: 2023/02/10 16:39:18 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipe	pipe;
	int 	status;

//	if (!initialize(&pipe, argc, argv, envp))
	if (!initialize_bonus(&pipe, argc, argv, envp))
		return (EXIT_FAILURE);
	status = pipex_bonus(&pipe);
//	status = pipex(&pipe);
//	system("leaks pipex");
	return (status);
}
