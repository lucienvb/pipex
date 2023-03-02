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

// error handling for one pipe
void	error_handling_one_pipe(int argc)
{
	if (argc != 5)
	{
		message_wrong_input(0);
		exit(EXIT_FAILURE);
	}
}
