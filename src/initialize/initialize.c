/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initialize.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/16 11:50:36 by lvan-bus      #+#    #+#                 */
/*   Updated: 2023/02/16 11:50:38 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// prepares a path_list (array) with the environment (envp) input
static void	init_path_list(t_pipe *p, char **envp)
{
	p->path_list = split_path(envp);
	if (!p->path_list)
		perror_and_exit("error: path not found\n");
}

static void	init_pipex(t_pipe *p, int argc, char **argv)
{
	p->infile = open(argv[1], O_RDONLY);
	if (p->infile == -1 || p->infile > OPEN_MAX)
		perror_and_exit("error: infile not found\n");
	p->child_count = argc - 3;
	p->cmd_index = FIRST_CMD;
	p->here_doc = 0;
}

static void	init_here_doc(t_pipe *p, int argc)
{
	p->infile = here_doc(p);
	p->child_count = argc - 4;
	p->cmd_index = FIRST_CMD_HD;
	p->here_doc = 1;
}

// initializes almost all variables declared in the struct s_pipe
void	initialize(t_pipe *p, int argc, char **argv, char **envp)
{
	init_path_list(p, envp);
	p->outfile = open(argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (p->outfile == -1 || p->outfile > OPEN_MAX)
		perror_and_exit("error: outfile not found\n");
	p->argv = argv;
	if (ft_strncmp(argv[1], "here_doc", 9) == 0)
		init_here_doc(p, argc);
	else
		init_pipex(p, argc, argv);
	p->last_cmd_index = argc - 2;
	p->envp = envp;
}
