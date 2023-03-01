/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   perror_and_exit.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/10 16:39:53 by lvan-bus      #+#    #+#                 */
/*   Updated: 2023/02/10 16:39:54 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error(void)
{
	perror("Error");
	exit(errno);
}

void	error_message(char *message)
{
	char	*sys_err_msg;

	sys_err_msg = ft_str_tolower(strerror(errno));
	ft_putstr_fd("zsh: ", STDERR_FILENO);
	ft_putstr_fd(sys_err_msg, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(message, STDERR_FILENO);
	ft_putchar_fd('\n', STDERR_FILENO);
	free(sys_err_msg);
	exit(errno);
}
