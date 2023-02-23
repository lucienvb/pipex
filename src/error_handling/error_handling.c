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

// error message wrong input one pipe
static bool	message_wrong_input(void)
{
	ft_printf("error: wrong input, please give the following:\n");
	ft_printf("[./pipex] [infile] [cmd1] [cmd2] [outfile]\n");
	return (false);
}

// error message wrong input multiple pipes
static bool	message_wrong_input_bonus(void)
{
	ft_printf("error: wrong input, please give the following:\n");
	ft_printf("[./pipex] [infile] [cmd1] [cmd2] [outfile]\n");
	ft_printf("--> two commands (cmd) or more\n");
	return (false);
}

// error handling for one pipe
bool	error_handling(int argc, char **argv)
{
	(void)argv;
	if (argc != 5)
		return (message_wrong_input());
	return (true);
}

// error handling for multiple pipes
bool	error_handling_bonus(int argc, char **argv)
{
	(void)argv;
	if (argc < 5)
		return (message_wrong_input_bonus());
	return (true);
}

