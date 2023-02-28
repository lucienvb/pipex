/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/27 16:51:35 by lvan-bus      #+#    #+#                 */
/*   Updated: 2023/02/27 16:51:36 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// 1) error handling
// 2) initializes all variables
// 3) executes pipex function and saves status on variable status
// 4) returns status
int	main(int argc, char **argv, char **envp)
{
	int		status;
	t_pipe	p;

	if (!error_handling_one_pipe(argc))
		return (EXIT_FAILURE);
	initialize(&p, argc, argv, envp);
	status = pipex(&p);
	return (status);
}
