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

// 1) initialize: error handling and initializes all variables
// 2) executes pipex function and saves status on variable status
// 3) returns status
int	main(int argc, char **argv, char **envp)
{
	int		status;
	t_pipe	p;

	if (!initialize(&p, argc, argv, envp))
		return (EXIT_FAILURE);
//	status = pipex_bonus(&pipe, pid);
	status = pipex(&p);
//	system("leaks pipex");
	return (status);
}
