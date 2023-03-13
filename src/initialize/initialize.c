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

// check exit codes
static void	no_infile(t_pipe *p)
{
	p->infile = open("no_infile", O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (p->infile == -1)
		exit(4);
	write(STDERR_FILENO, "zsh: no such file or directory: ", 32);
	write(STDERR_FILENO, p->argv[1], ft_strlen(p->argv[1]));
	write(STDERR_FILENO, "\n", 1);
}

// prepares a path_list (array) with the environment (envp) input
void	init_path_list(t_pipe *p, char **envp)
{
	p->path_list = split_path(envp);
	if (!p->path_list)
		error_message("PATH not found", 0);
}

void	init_pipex(t_pipe *p, int argc, char **argv)
{
	p->infile = open(argv[1], O_RDONLY);
	if (p->infile == -1 || p->infile > FOPEN_MAX)
		no_infile(p);
	p->child_count = argc - 3;
	p->cmd_index = FIRST_CMD;
	p->random = 0;
	if (ft_strncmp(argv[2], "cat /dev/random", 15) == 0)
		p->random = 1;
	p->here_doc = 0;
}

// initializes almost all variables declared in the struct s_pipe
void	initialize(t_pipe *p, int argc, char **argv, char **envp)
{
	init_path_list(p, envp);
	p->outfile = open(argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (p->outfile == -1 || p->outfile > FOPEN_MAX)
		error_message(argv[argc - 1], 0);
	p->argv = argv;
	init_pipex(p, argc, argv);
	p->last_cmd_index = argc - 2;
	p->envp = envp;
	if (dup2(p->infile, STDIN_FILENO) == -1)
		exit(4);
	close(p->infile);
}
