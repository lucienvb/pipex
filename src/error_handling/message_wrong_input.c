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
void	message_wrong_input(int bonus)
{
	ft_putstr_fd("format: ./pipex [infile] [cmd1] [cmd2]", STDERR_FILENO);
	if (bonus)
		ft_putstr_fd(" [...]", STDERR_FILENO);
	ft_putstr_fd(" [outfile]\n", STDERR_FILENO);
}
