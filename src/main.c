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

//static void	test(void)
//{
//	system("leaks pipex");
//}

int	main(int argc, char **argv, char **envp)
{
	t_pipe	data;

//	atexit(test);
	if (!initialize(&data, argc, argv, envp))
		return (0);
	pipex(&data);
//	system("leaks pipex");
	return (0);
}
