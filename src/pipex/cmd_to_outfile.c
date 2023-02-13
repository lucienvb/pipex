/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cmd_to_outfile.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/10 16:41:32 by lvan-bus      #+#    #+#                 */
/*   Updated: 2023/02/10 16:41:34 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	**join_three(char *s1, char *s2, char *s3)
{
	char		**ret;

	if (!s1 || !s2 || !s3)
		return (NULL);
	ret = malloc(4 * sizeof(char *));
	if (!ret)
		return (NULL);
	ret[0] = ft_strdup(s1);
	ret[1] = ft_strdup(s2);
	ret[2] = ft_strdup(s3);
	ret[3] = NULL;
	return (ret);
}

int	cmd_to_outfile(int argc, char **argv, char **envp)
{
	char	**file_tmp;
	char	*file;
	int		fd;

	(void)argc;
	(void)envp;
	fd = open(argv[3], O_CREAT | O_TRUNC | O_WRONLY);
	if (fd == -1)
		perror_and_exit("open");
	if (dup2(fd, STDOUT_FILENO) == -1)
		perror_and_exit("dup2");
	file_tmp = ft_split(argv[2], ' ');
	file = ft_strjoin("/bin/", file_tmp[0]);
	file_tmp = join_three(file_tmp[0], file_tmp[1], argv[1]);
	if (execve(file, file_tmp, NULL) == -1)
	{
		perror("execve");
		exit(EXIT_FAILURE);
	}
	return (0);
}