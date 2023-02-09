/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <lvan-bus@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/10 12:22:34 by lvan-bus      #+#    #+#                 */
/*   Updated: 2023/01/10 16:50:19 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

// DEFINE PERCENTAGE SIGN (PS)
# ifndef PS
#  define PS '%'
# endif

// INCLUDE
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <stddef.h>
# include <limits.h>

// PRINTF
int		ft_printf(const char *s, ...);

// UTILS -- pf_HEX
int		put_hex(va_list ap);
int		put_hex_upper(va_list ap);
int		put_ptr(va_list ap);

// UTILS -- pf_ITOA
char	*pf_itoa(int n);
char	*pf_utoa(unsigned int n);

// UTILS -- pf_MEMCPY
void	*pf_memcpy(void *dst, void *src, size_t n);

// UTILS -- pf_PUTS
int		put_str(va_list ap);
int		put_chr(va_list ap);
int		put_int(va_list ap);
int		put_uint(va_list ap);
int		write_chr(char c);

// UTILS -- pf_STR
void	str_toupper(char *s);
int		pf_strlen(const char *str);
char	*pf_strdup(const char *s1);
int		pf_strncmp(const char *s1, const char *s2, size_t n);
char	*pf_substr(char const *s, unsigned int start, size_t len);

#endif
