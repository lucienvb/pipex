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

void	error_message(char *message, int errnum)
{
	char	*sys_err_msg;

	if (errnum == 127)
		sys_err_msg = ft_strdup("command not found", 0);
	else
		sys_err_msg = ft_str_tolower(strerror(errno));
	put_err_msg(message, sys_err_msg);
	free(sys_err_msg);
	if (errnum == 127 || errnum == 0)
		exit(errnum);
	else
		exit(errno);
}

//void	error_message(char *message, int errnum, t_pipe *p)
//{
//	char	*sys_err_msg;
//	int		fd[2];
//
//	if (errnum == 127)
//		sys_err_msg = ft_strdup("command not found", 0);
//	else
//		sys_err_msg = ft_str_tolower(strerror(errno));
//	put_err_msg(message, sys_err_msg);
//	free(sys_err_msg);
//	p->cmd_index = p->last_cmd_index;
//	pipe_create(fd);
//	execute_child(p, fd);
//	close(p->outfile);
//	remove_split(p->path_list);
//	if (errnum == 127 || errnum == 0)
//		exit(errnum);
//	else
//		exit(errno);
//}
