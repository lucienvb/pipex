/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_path_and_argv.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/16 14:09:58 by lvan-bus      #+#    #+#                 */
/*   Updated: 2023/02/16 14:10:00 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	**get_new_argv(char *infile, char **argv)
{
	char	**new_argv;
	size_t	len;
	size_t	i;

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

// creates utils: utils to the called command
// creates new_argv: array with 1) the command
// 2) the flags 3) the infile
// need to take a look at the perror_and_exit message
char	**init_path_and_argv(t_pipe *pipe, char **new_argv)
{
	int	i;
	int	j;

	i = pipe->cmd_index;
	new_argv = ft_split(pipe->argv[i], ' ');
	pipe->p_index = access_to_index(pipe->path_list, new_argv[0]);
	j = pipe->p_index;
	if (j == -1)
		perror_and_exit("command not found");
	pipe->path = strjoin_three(pipe->path_list[j], "/", new_argv[0]);
	if (i == FIRST_CMD)
		new_argv = get_new_argv(pipe->argv[1], new_argv);
	return (new_argv);
}
