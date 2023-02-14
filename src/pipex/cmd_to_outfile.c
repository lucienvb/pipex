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

//
static char	**init_pipe_data(t_pipe *data, char **new_argv)
{
	new_argv = ft_split(data->argv[2], ' ');
	data->p_index = access_to_index(data->path_list, new_argv[0]);
	data->path = strjoin_three(data->path_list[data->p_index], "/", new_argv[0]);
	new_argv = get_new_argv(data->argv[1], new_argv);
	return (new_argv);
}

// opens a path (argv[3]) to write to with the dup2 function
// the path is in this case the outfile
static void	init_to_outfile(int *fd, t_pipe *data)
{
	int i;

	i = data->end;
	*fd = open(data->argv[i], O_CREAT | O_TRUNC | O_WRONLY);
	if (*fd == -1)
		perror_and_exit("open");
	if (dup2(*fd, STDOUT_FILENO) == -1)
		perror_and_exit("dup2");
}

int	cmd_to_outfile(t_pipe *data)
{
	char	**new_argv;
	int		fd;

	init_to_outfile(&fd, data);
	new_argv = NULL;
	new_argv = init_pipe_data(data, new_argv);
	if (execve(data->path, new_argv, NULL) == -1)
	{
		perror("execve");
		exit(EXIT_FAILURE);
	}
	return (0);
}
