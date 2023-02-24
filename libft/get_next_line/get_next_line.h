/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/24 15:05:43 by lvan-bus      #+#    #+#                 */
/*   Updated: 2023/02/24 15:05:44 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

// INCLUDE
# include <stddef.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "../libft.h"

// DEFINE
# if BUFFER_SIZE < 1 || BUFFER_SIZE >= 10000000
#  undef BUFFER_SIZE
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 128
# endif

// GET_NEXT_LINE
char	*get_next_line(int fd);

// UTILS
void	*gnl_memcpy(void *dst, const char *src, size_t n);
char	*gnl_strdup(char *s1);
char	*gnl_substr(char *s, unsigned int start, size_t len, int free_s);
char	*gnl_strjoin(char *s1, char *s2);
char	*gnl_strchr(const char *s, int c);
void	gnl_print_fd(int fd);

#endif
