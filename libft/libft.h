/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 15:45:13 by lvan-bus      #+#    #+#                 */
/*   Updated: 2023/01/20 15:27:46 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include "ft_printf/ft_printf.h"

// STRUCTURES
typedef struct node
{
	int				content;
	int				index;
	int				size;
	struct node		*next;
}					t_node;

// ASCII
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);

// CONVERT
int		ft_atoi(const char *str);
int		ft_atoi_with_overflow(const char *str, int *result);
char	*ft_itoa(int n);
int		ft_tolower(int c);
int		ft_toupper(int c);

// ERROR HANDLING
size_t	error_double_check(char **argv);
size_t	error_limit_check(char **argv);
size_t	error_num_check(char *str);
size_t	error_num_check_for_2d_array(char **argv);
bool	input_parsing(int argc, char **argv);

// LISTS
int		add_back(t_node **head, int content);
int		find_list_lowest(t_node **stack, int low);
t_node	*list_last(t_node *stack);
int		list_reversed_sorted(t_node *stack);
int		list_size(t_node *stack);
int		list_sorted(t_node *stack);
t_node	*new_list(t_node *stack, char **argv);
size_t	node_count(t_node *stack);

// MEM
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memset(void *b, int c, size_t len);

// PUT
void	ft_print_list(char **list);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);

// STR
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *str);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strrchr(const char *s, int c);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	word_count(char const *s, char c);

#endif
