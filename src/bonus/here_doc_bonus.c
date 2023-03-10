/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   here_doc.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/27 15:15:44 by lvan-bus      #+#    #+#                 */
/*   Updated: 2023/02/27 16:52:28 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	exit_d_check(char *line, t_pipe *p)
{
	(void)p;
	if (!line)
	{
		write(STDERR_FILENO, "\n", 1);
		remove_split(p->path_list);
		exit(EXIT_FAILURE);
	}
}

int	here_doc(t_pipe *p)
{
	int		hd;
	int		fd[2];
	char	*line;

	hd = 0;
	pipe_create(fd);
	while (1)
	{
		write(STDOUT_FILENO, "pipe heredoc> ", 14);
		if (dup2(hd, STDIN_FILENO) == -1)
			error_message("", 0);
		line = get_next_line(hd);
		exit_d_check(line, p);
		if (ft_strncmp(line, p->argv[LIM], ft_strlen(p->argv[LIM])) == 0)
		{
			free(line);
			break ;
		}
		write(fd[1], line, ft_strlen(line));
		free(line);
	}
	close(fd[1]);
	close(hd);
	return (fd[0]);
}
