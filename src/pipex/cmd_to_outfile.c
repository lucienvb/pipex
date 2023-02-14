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

//static char	**join_three(char *s1, char *s2, char *s3)
//{
//	char	**ret;
//
////	if (!s1 || !s2 || !s3)
////		return (NULL);
//	ret = malloc(4 * sizeof(char *));
//	if (!ret)
//		return (NULL);
//	ret[0] = ft_strdup(s1);
//	ret[1] = ft_strdup(s2);
//	ret[2] = ft_strdup(s3);
//	ret[3] = NULL;
//	return (ret);
//}

static size_t ft_array_len(char **array)
{
	size_t len;

	if (!array || !array[0])
		return (0);
	len = 0;
	while (array[len])
		len++;
	return (len);
}

static char	**get_new_argv(char *infile, char **argv)
{
	char 	**new_argv;
	size_t	len;
	size_t	i;

	// maybe use perror or exit or something else here instead of returning NULL
	if (!infile || !argv[0])
		return (NULL);
	len = ft_array_len(argv);
	new_argv = malloc((len + 2) * sizeof(char *));
	if (!new_argv)
		return (NULL);
	i = 0;
	while (argv[i])
	{
		new_argv[i] = argv[i];
		i++;
	}
	new_argv[i++] = ft_strdup(infile);
	new_argv[i] = NULL;
	return (new_argv);
}

int	cmd_to_outfile(int argc, char **argv, t_pipe *data)
{
	char	**new_argv;
	int		fd;

	(void)argc;
	fd = open(argv[3], O_CREAT | O_TRUNC | O_WRONLY);
	if (fd == -1)
		perror_and_exit("open");
	if (dup2(fd, STDOUT_FILENO) == -1)
		perror_and_exit("dup2");

	new_argv = ft_split(argv[2], ' ');
	data->p_index = access_to_index(data->path_list, new_argv[0]);
	data->path = strjoin_three(data->path_list[data->p_index], "/", new_argv[0]);
	new_argv = get_new_argv(argv[1], new_argv);
	if (execve(data->path, new_argv, NULL) == -1)
	{
		ft_printf("kom ik hier1?\n");
		perror("execve");
		exit(EXIT_FAILURE);
	}
	ft_printf("kom ik hier2?\n");
	return (0);
}
