/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   message_wrong_input.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/27 15:16:29 by lvan-bus      #+#    #+#                 */
/*   Updated: 2023/02/27 15:16:30 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// error message wrong input one pipe with option for
// extra message bonus
bool	message_wrong_input(int bonus)
{
	ft_putstr_fd("wrong input, please give the following:\n", STDERR_FILENO);
	ft_putstr_fd("[./pipex] [infile] [cmd1] [cmd2] [outfile]\n", STDERR_FILENO);
	if (bonus)
		ft_putstr_fd("--> two commands (cmd) or more\n", STDERR_FILENO);
	return (false);
}

// error message wrong input for here_doc
bool	message_wrong_input_here_doc(void)
{
	ft_putstr_fd("wrong input, please give the following:\n", STDERR_FILENO);
	ft_putstr_fd("[./pipex] [here_doc] [LIMITER] [cmd] [cmd1]", STDERR_FILENO);
	ft_putstr_fd(" [outfile]\n", STDERR_FILENO);
	return (false);
}
