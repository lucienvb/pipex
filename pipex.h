/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <lvan-bus@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/07 11:08:22 by lvan-bus      #+#    #+#                 */
/*   Updated: 2023/01/17 13:05:32 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

// INCLUDE
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdbool.h>
# include <fcntl.h>
# include <string.h>
# include "./libft/libft.h"
# include <sys/wait.h>
# include <sys/errno.h>

// DEFINE
# define FIRST_CMD 2
# define FIRST_CMD_HD 3
# define LIM 2
# define PIPE_READ_INDEX 0
# define PIPE_WRITE_INDEX 1

// STRUCTURES
typedef struct s_pipe
{
	size_t	last_cmd_index;
	char	**path_list;
	size_t	child_count;
	size_t	cmd_index;
	size_t	here_doc;
	int		outfile;
	int		infile;
	char	**envp;
	int		random;
	char	**argv;
	char	*path;
}	t_pipe;

void	init_random(t_pipe *p, int *fd);

// BONUS
void	error_handling(int argc);
int		here_doc(t_pipe *p);
void	initialize_bonus(t_pipe *p, int argc, char **argv, char **envp);
void	init_here_doc(t_pipe *p, int argc);

// CHILD FUNCTIONS
void	execute_child(t_pipe *p, int *fd);
pid_t	child_create(void);
void	child_wait(t_pipe *p, pid_t *pid, int *status);

// FUNCTIONS
void	error(void);
void	error_handling_one_pipe(int argc);
void	message_wrong_input(int bonus);
//bool 	message_wrong_input_here_doc(void);
void	error_message(char *message, int errnum);

// INITIALIZE
void	initialize(t_pipe *p, int argc, char **argv, char **envp);
void	init_in_and_outfile(t_pipe *p, int *fd);
char	**init_path_and_argv(t_pipe *p, char **new_argv);
void	init_pipex(t_pipe *p, int argc, char **argv);
void	init_path_list(t_pipe *p, char **envp);

// PIPE FUNCTIONS
int		pipex(t_pipe *p);
void	pipe_create(int *fd);

// UTILS
int		access_to_index(char **path, char *system_call);
void	execute_parent(int *fd);
void	execute_parent_end(t_pipe *p, int *status, pid_t *child, int *fd);
char	**split_path(char **envp);
char	*strjoin_three(char *s1, char *s2, char *s3);

#endif
