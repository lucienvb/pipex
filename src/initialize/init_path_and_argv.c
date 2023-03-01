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

// function that prepares a new_argv for the first command
static char	**get_new_argv(char *infile, char **argv)
{
	char	**new_argv;
	size_t	len;
	size_t	i;

	if (!argv[0])
		return (NULL);
	len = ft_array_len(argv);
	new_argv = malloc((len + 2) * sizeof(char *));
	if (!new_argv)
		return (free(argv), NULL);
	i = 0;
	while (argv[i])
	{
		new_argv[i] = argv[i];
		i++;
	}
	free(argv);
	new_argv[i++] = ft_strdup(infile, 0);
	new_argv[i] = NULL;
	return (new_argv);
}

// creates new_argv: array with 1) the command
// 2) the flags 3) the infile (only for the first command)
char	**init_path_and_argv(t_pipe *p, char **new_argv)
{
	int	cmd_path;

	new_argv = ft_split(p->argv[p->cmd_index], ' ');
	cmd_path = access_to_index(p->path_list, new_argv[0]);
	if (cmd_path == -1)
		error_message("Command not found");
	p->path = strjoin_three(p->path_list[cmd_path], "/", new_argv[0]);
	if (p->cmd_index == FIRST_CMD && !p->here_doc)
		new_argv = get_new_argv(p->argv[1], new_argv);
	return (new_argv);
}
