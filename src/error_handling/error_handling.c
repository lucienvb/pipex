/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   p_input_parsing.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/10 16:39:40 by lvan-bus      #+#    #+#                 */
/*   Updated: 2023/02/10 16:39:41 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex.h"

// error message wrong input one pipe with option for
// extra message bonus
static bool	message_wrong_input(int bonus)
{
	ft_printf("error: wrong input, please give the following:\n");
	ft_printf("[./pipex] [infile] [cmd1] [cmd2] [outfile]\n");
	if (bonus)
		ft_printf("--> two commands (cmd) or more\n");
	return (false);
}

// error message wrong input for here_doc
static bool	message_wrong_input_here_doc(void)
{
	ft_printf("error: wrong input, please give the following:\n");
	ft_printf("[./pipex] [here_doc] [LIMITER] [cmd] [cmd1] [outfile]\n");
	return (false);
}

// error handling for one pipe
bool	error_handling(int argc)
{
	if (argc != 5)
		return (message_wrong_input(0));
	return (true);
}

// error handling for multiple pipes
bool	error_handling_multiple_pipes(int argc)
{
	if (argc < 5)
		return (message_wrong_input(1));
	return (true);
}

bool	error_handling_here_doc(int argc)
{
	if (argc < 6)
		return (message_wrong_input_here_doc());
	return (true);
}
