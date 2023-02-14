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

// In this function the command ls -l is executed for an
// input file of choose and then writes it to an output
// file of choice.
int	main(int argc, char **argv, char **envp)
{
	t_pipe	data;

	(void)envp;
	if (!initialize(&data, argc, argv, envp))
		return (0);
//	pipex(argc, argv, &data);
	cmd_to_outfile(argc, argv, &data);
//	system("leaks pipex");
	return (0);
}

// In this function two child processes are created that
// communicate via a pipe.
// The first child process is multiplying input 'a' (integer)
// with 2, the second child process is multiplying the result
// of the first child process with 3.
/*int	main(int argc, char **argv, char **envp)
{
	int 	a;

	(void)envp;
	if (!p_input_parsing(argc, argv))
		return (0);
	a = ft_atoi(argv[1]);
	pipex(a);
	return (0);
}*/
