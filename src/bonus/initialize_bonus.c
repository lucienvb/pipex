/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initialize_bonus.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/27 16:52:54 by lvan-bus      #+#    #+#                 */
/*   Updated: 2023/02/27 16:52:56 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	set_outfile(t_pipe *p, int argc, char **argv)
{
	if (ft_strncmp(argv[1], "here_doc", 9) == 0)
		p->outfile = open(argv[argc - 1], O_RDWR | O_CREAT | O_APPEND, 0644);
	else
		p->outfile = open(argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (p->outfile == -1 || p->outfile > FOPEN_MAX)
		error_message(argv[argc - 1]);
}

void	initialize_bonus(t_pipe *p, int argc, char **argv, char **envp)
{
	init_path_list(p, envp);
	set_outfile(p, argc, argv);
	p->argv = argv;
	if (ft_strncmp(argv[1], "here_doc", 9) == 0)
		init_here_doc(p, argc);
	else
		init_pipex(p, argc, argv);
	p->last_cmd_index = argc - 2;
	p->envp = envp;
}
