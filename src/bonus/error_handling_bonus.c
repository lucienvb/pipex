/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_handling_bonus.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/27 16:51:56 by lvan-bus      #+#    #+#                 */
/*   Updated: 2023/02/27 16:51:57 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// error handling for multiple pipes
static bool	error_handling_multiple_pipes(int argc)
{
	if (argc < 5)
		return (message_wrong_input(1));
	return (true);
}

static bool	error_handling_here_doc(int argc)
{
	if (argc < 6)
		return (message_wrong_input_here_doc());
	return (true);
}

bool	error_handling(int argc, char **argv)
{
	if (ft_strncmp(argv[1], "here_doc", 9) == 0)
		return (error_handling_here_doc(argc));
	else
		return (error_handling_multiple_pipes(argc));
}
