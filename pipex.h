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

// STRUCTURES
typedef struct s_pipe
{
	size_t	last_cmd_index;
	char	**path_list;
	size_t	child_count;
	size_t	cmd_index;
	int		no_infile;
//	char	*no_inf;
	int		here_doc;
	int		outfile;
	int		infile;
	char	**envp;
	char	**argv;
	char	*path;
}	t_pipe;

// BONUS
void	error_handling(int argc);
int		here_doc(t_pipe *p);
void	initialize_bonus(t_pipe *data, int argc, char **argv, char **envp);
void	init_here_doc(t_pipe *p, int argc);

// CHILD FUNCTIONS
int		execute_child(t_pipe *pipe, int *pipe_fd);
pid_t	child_create(pid_t pid);
void	child_wait(t_pipe *pipe, pid_t *pid, int *status);

// FUNCTIONS
void	error(void);
void	error_handling_one_pipe(int argc);
void	message_wrong_input(int bonus);
//bool 	message_wrong_input_here_doc(void);
void	error_message(char *message, int errnum, t_pipe *p);

// INITIALIZE
void	initialize(t_pipe *data, int argc, char **argv, char **envp);
void	init_in_and_outfile(t_pipe *data, int *pipe_fd);
char	**init_path_and_argv(t_pipe *data, char **new_argv);
void	init_pipex(t_pipe *p, int argc, char **argv);
void	init_path_list(t_pipe *p, char **envp);

// PIPE FUNCTIONS
int		pipex(t_pipe *data);
void	pipe_create(int *pipe_fd);
void	pipes_close(int *pipe_fd);

// UTILS
int		access_to_index(char **path, char *system_call);
void	execute_parent(int *pipe_fd);
void	execute_parent_end(t_pipe *p, int *status, pid_t *child);
char	**split_path(char **envp);
char	*strjoin_three(char *s1, char *s2, char *s3);

#endif
