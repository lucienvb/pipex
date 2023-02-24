#include "pipex.h"

void	here_doc(void)
{
	int		fd;
	char	*line;

	write(STDOUT_FILENO, "> \n", 3);
	fd = open("cheese.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("line: %s\n", line);
	free(line);
	close(fd);
	exit(EXIT_SUCCESS);
}