/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_puts.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <lvan-bus@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/10 12:22:36 by lvan-bus      #+#    #+#                 */
/*   Updated: 2023/01/10 12:22:37 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_str(va_list ap)
{
	char	*s;

	s = va_arg(ap, char *);
	if (!s)
		return (write(STDOUT_FILENO, "(null)", 6));
	return (write(STDOUT_FILENO, s, pf_strlen(s)));
}

int	put_chr(va_list ap)
{
	char	c;

	c = va_arg(ap, int);
	return (write(STDOUT_FILENO, &c, 1));
}

int	put_int(va_list ap)
{
	long		num;
	char		*str;

	num = va_arg(ap, signed int);
	str = pf_itoa(num);
	if (!str)
		return (0);
	num = pf_strlen(str);
	write(STDOUT_FILENO, str, num);
	free(str);
	return (num);
}

int	put_uint(va_list ap)
{
	unsigned int	num;
	char			*str;

	num = va_arg(ap, unsigned int);
	str = pf_utoa(num);
	if (!str)
		return (0);
	num = pf_strlen(str);
	write(STDOUT_FILENO, str, num);
	free(str);
	return (num);
}

int	write_chr(char c)
{
	if (c != '%')
		return (write(STDOUT_FILENO, &c, 1));
	return (0);
}
