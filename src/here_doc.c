#include "pipex.h"

void	here_doc(char **argv)
{
	int		fd;
	char	*line;

	fd = 0;
//	fd = open("text.txt", O_RDONLY);
	while (1)
	{
		write(STDOUT_FILENO, "> ", 2);
		if (dup2(fd, STDIN_FILENO) == -1)
			perror_and_exit("dup2");
		line = get_next_line(fd);
//		ft_printf("%s\n", line);
		if (ft_strncmp(line, argv[2], ft_strlen(argv[2])) == 0)
		{
			free(line);
			break ;
		}
		free(line);
//		write(fd, "\n", 1);
	}
	ft_printf("kom ik hier?\n");
//	gnl_print_fd(fd);
	close(fd);
	exit(EXIT_SUCCESS);
}

//void	here_doc(char **argv)
//{
//	int	fd;
//
//	(void)argv;
//	fd = open("cheese.txt", O_RDONLY);
//	gnl_print_fd(fd);
//	exit(EXIT_SUCCESS);
//}