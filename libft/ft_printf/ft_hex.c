/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_hex.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <lvan-bus@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/10 12:22:21 by lvan-bus      #+#    #+#                 */
/*   Updated: 2023/01/10 12:22:22 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	numlen_hex(unsigned long n)
{
	int		len;

	len = 0;
	if (n == 0)
		len++;
	while (n)
	{
		n /= 16;
		len++;
	}
	return (len);
}

static char	*pf_itoh(unsigned long n)
{
	unsigned long	numlen;
	char			*hex;
	char			*str;

	hex = "0123456789abcdef";
	numlen = numlen_hex(n);
	str = malloc((numlen + 1) * sizeof(char));
	if (!str)
		return (NULL);
	if (n == 0)
		str[0] = '0';
	str[numlen--] = '\0';
	while (n)
	{
		str[numlen--] = hex[n % 16];
		n /= 16;
	}
	return (str);
}

int	put_hex(va_list ap)
{
	unsigned int		num;
	char				*str;

	num = va_arg(ap, unsigned int);
	str = pf_itoh(num);
	if (!str)
		return (0);
	num = numlen_hex(num);
	write(STDOUT_FILENO, str, num);
	free(str);
	return (num);
}

int	put_hex_upper(va_list ap)
{
	unsigned int		num;
	char				*str;

	num = va_arg(ap, unsigned int);
	str = pf_itoh(num);
	if (!str)
		return (0);
	str_toupper(str);
	num = numlen_hex(num);
	write(STDOUT_FILENO, str, num);
	free(str);
	return (num);
}	

int	put_ptr(va_list ap)
{
	char			*ptr;
	unsigned long	num;

	num = va_arg(ap, unsigned long);
	ptr = pf_itoh(num);
	if (!ptr)
		return (0);
	write(1, "0x", 2);
	num = numlen_hex(num);
	write(STDOUT_FILENO, ptr, num);
	free(ptr);
	return (2 + num);
}
