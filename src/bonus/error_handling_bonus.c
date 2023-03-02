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

void	error_handling(int argc)
{
	if (argc < 5)
	{
		message_wrong_input(1);
		exit(EXIT_FAILURE);
	}
}
