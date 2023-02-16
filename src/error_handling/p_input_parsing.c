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

#include "pipex.h"

static bool	message_wrong_input(void)
{
	ft_printf("error: wrong input, please give the following:\n");
	ft_printf("[pipex] [infile] [cmd1] [cmd2] [outfile]\n");
	return (false);
}

bool	p_input_parsing(int argc, char **argv)
{
	(void)argv;
	if (argc != 5)
		return (message_wrong_input());
	return (true);
}
