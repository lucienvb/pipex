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

static void	put_err_msg(char *msg, char *sys_err_msg)
{
	ft_putstr_fd("zsh: ", STDERR_FILENO);
	ft_putstr_fd(sys_err_msg, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(msg, STDERR_FILENO);
	ft_putchar_fd('\n', STDERR_FILENO);
}

void	error_message(char *message, int errnum, t_pipe *p)
{
	char	*sys_err_msg;

	(void)p;
	if (errnum == 127)
		sys_err_msg = ft_strdup("command not found", 0);
	else
		sys_err_msg = ft_str_tolower(strerror(errno));
	put_err_msg(message, sys_err_msg);
	free(sys_err_msg);
	if (errnum == 127)
		exit(errnum);
	else
		exit(errno);
}
