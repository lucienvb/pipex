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
# include "./libft/libft.h"

// DEFINE
# define FIRST_CMD 2
# define FD_SIZE 2
#

// STRUCTURES
typedef struct s_pipe
{
	int 	end;
	int 	cmd_index;
	int		last_cmd_index;
	char 	**argv;
	char	**path_list;
	char 	*path;
	int 	p_index;
	size_t	child_count;
}	t_pipe;

// FUNCTIONS
bool	error_handling(int argc, char **argv);
void	perror_and_exit(char *str);

// CHILD FUNCTIONS
pid_t	child_create(pid_t pid);
void	child_wait(t_pipe *pipe);

// EXECUTE
int		execute_cmd_and_write(t_pipe *data, int *pipe_fd);
void	init_in_and_outfile(t_pipe *data, int *pipe_fd);
char	**init_path_and_argv(t_pipe *data, char **new_argv);

// INITIALIZE
bool	initialize(t_pipe *data, int argc, char **argv, char **envp);

// PIPE FUNCTIONS
void	pipex(t_pipe *data);
void	pipe_create(int *pipe_fd);
void	pipes_close(int *pipe_fd);

// PATH RELATED FUNCTIONS
char	**split_path(char **envp);
int		access_to_index(char **path, char *system_call);

// UTILS
char	*strjoin_three(char *s1, char *s2, char *s3);

#endif
