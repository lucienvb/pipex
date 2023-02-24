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

// DEFINE
# define FIRST_CMD 2

// STRUCTURES
typedef struct s_pipe
{
	size_t	last_cmd_index;
	char	**path_list;
	size_t	child_count;
	size_t	cmd_index;
	int		outfile;
	int		infile;
	char	**envp;
	char	**argv;
	char	*path;
}	t_pipe;

// BONUS
bool	error_handling_bonus(int argc, char **argv);
void	here_doc(char **argv);

// FUNCTIONS
bool	error_handling(int argc);
bool	error_handling_here_doc(int argc);
bool	error_handling_multiple_pipes(int argc);
void	perror_and_exit(char *str);

// CHILD FUNCTIONS
int		execute_child(t_pipe *pipe, int *pipe_fd);
pid_t	child_create(pid_t pid);
void	child_wait(t_pipe *pipe, pid_t *pid, int *status);

// INITIALIZE
bool	initialize(t_pipe *data, int argc, char **argv, char **envp);
void	init_in_and_outfile(t_pipe *data, int *pipe_fd);
char	**init_path_and_argv(t_pipe *data, char **new_argv);

// PIPE FUNCTIONS
int		pipex(t_pipe *data);
void	pipe_create(int *pipe_fd);
void	pipes_close(int *pipe_fd);

// UTILS
int		access_to_index(char **path, char *system_call);
void	execute_parent(int *pipe_fd);
void	execute_parent_end(t_pipe *pipe, int *pipe_fd, int *status, pid_t *pid);
char	**split_path(char **envp);
char	*strjoin_three(char *s1, char *s2, char *s3);

#endif
