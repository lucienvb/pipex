/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/24 15:04:53 by lvan-bus      #+#    #+#                 */
/*   Updated: 2023/02/24 15:04:55 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_line(int fd, char *temp)
{
	char	buf[BUFFER_SIZE + 1];
	int		read_ret;

	read_ret = 1;
	while (!gnl_strchr(temp, '\n') && read_ret != 0)
	{
		read_ret = read(fd, buf, BUFFER_SIZE);
		if (read_ret == -1)
			return (free(temp), NULL);
		buf[read_ret] = '\0';
		if (!temp)
			temp = gnl_strdup(buf);
		else
			temp = gnl_strjoin(temp, buf);
		if (!temp || temp[0] == '\0')
			return (free(temp), NULL);
	}
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*temp;
	char		*line;
	int			i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	temp = read_line(fd, temp);
	if (!temp)
		return (NULL);
	i = 0;
	while (temp[i] && temp[i] != '\n')
		i++;
	if (temp[i] == '\n')
		line = gnl_substr(temp, 0, ++i, 0);
	else
		line = gnl_substr(temp, 0, i, 0);
	if (!line)
		return (free(temp), NULL);
	temp = gnl_substr(temp, i, (ft_strlen(temp) - i), 1);
	if (!temp)
		return (NULL);
	return (line);
}

// #include <stdio.h>
// int	main(void)
// {
// 	int	fd;
// 	int	i;
// 	char	*word;

// 	i = 0;
// 	fd = open("bacon.txt", O_RDONLY);
// 	while (i < 15)
// 	{
// 		word = get_next_line(fd);
// 		printf("%s", word);
// 		free(word);
// 		i++;
// 	}
// 	close(fd);
// 	return (0);
// }
