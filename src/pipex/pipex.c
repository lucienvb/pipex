/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/10 16:41:47 by lvan-bus      #+#    #+#                 */
/*   Updated: 2023/02/10 16:41:49 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//static void	execute_first_child(int *a, int *pipe_fd, char *mes)
static void	execute_first_child(t_pipe *data, int *pipe_fd)
{
	cmd_to_pipe(data, pipe_fd);
	close_pipes(pipe_fd);
	ft_printf("first child process\n");
}

static void	execute_second_child(t_pipe *data, int *pipe_fd)
{
	char	buf[999];
	int 	bytes_read;

	(void)data;
	bytes_read = read(pipe_fd[0], buf, 999);
	buf[bytes_read] = '\0';
	close_pipes(pipe_fd);
//	*a *= 3;
	ft_printf("buf:\n%s\n", buf);
}

void	pipex(t_pipe *data)
{
	int		pipe_fd[2];
	pid_t	pid[2];

	create_pipe(pipe_fd);
	pid[0] = create_child(pid[0]);
	if (pid[0] == 0)
		execute_first_child(data, pipe_fd);
	else
	{
		pid[1] = create_child(pid[1]);
		if (pid[1] == 0)
			execute_second_child(data, pipe_fd);
		else
		{
			close_pipes(pipe_fd);
			wait_for_child();
			ft_printf("I am the parent process\n");
		}
	}
}
