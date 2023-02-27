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

int	here_doc(t_pipe *p)
{
	int		hd;
	int		fd[2];
	char	*line;

	hd = 0;
	pipe_create(fd);
	while (1)
	{
		write(STDOUT_FILENO, "> ", 2);
		if (dup2(hd, STDIN_FILENO) == -1)
			perror_and_exit("dup2");
		line = get_next_line(hd);
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
