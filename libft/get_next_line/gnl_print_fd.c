/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gnl_print_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/24 15:52:49 by lvan-bus      #+#    #+#                 */
/*   Updated: 2023/02/24 15:52:51 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	gnl_print_fd(int fd)
{
	char	*line;

	while (1)
	{
		line = get_next_line(fd);
		if (!line)
		{
			free(line);
			break ;
		}
		ft_printf("%s", line);
		free(line);
	}
//	close(fd);
}
