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
# define FIRST "first"
# define SECOND "second"

// STRUCTURES
typedef struct s_pipe
{
//	int 	argc;
//	char 	**argv;
	char	**path_list;
	char 	*path;
	int 	p_index;
}	t_pipe;

// FUNCTIONS
bool	p_input_parsing(int argc, char **argv);
void	perror_and_exit(char *str);
void	pipex(int a);

// CHILD FUNCTIONS
pid_t	create_child(pid_t pid);
void	wait_for_child(void);

// INITIALIZE
bool	initialize(t_pipe *data, int argc, char **argv, char **envp);

// PIPE FUNCTIONS
void	create_pipe(int *pipe_fd);
void	close_pipes(int *pipe_fd);

// FUNCTION FOR EXECUTING A COMMAND ON A INFILE AND WRITE TO OUTFILE
int		cmd_to_outfile(int argc, char *argv[], t_pipe *data);

// PATH RELATED FUNCTIONS
char	**split_path(char **envp);
int		access_to_index(char **path, char *system_call);

// UTILS
char	*strjoin_three(char *s1, char *s2, char *s3);

#endif
