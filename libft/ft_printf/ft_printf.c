/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <lvan-bus@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/10 12:22:31 by lvan-bus      #+#    #+#                 */
/*   Updated: 2023/01/10 12:23:09 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	put_perc(va_list ap)
{
	(void) ap;
	return (write(STDOUT_FILENO, "%", 1));
}

static int	(*find_token(char *c))(va_list ap)
{
	static void	*func[9][2] = {
	{"c", put_chr},
	{"s", put_str},
	{"p", put_ptr},
	{"d", put_int},
	{"i", put_int},
	{"u", put_uint},
	{"x", put_hex},
	{"X", put_hex_upper},
	{"%", put_perc}
	};
	int			i;

	i = 0;
	while (i < 9)
	{
		if (pf_strncmp(func[i][0], c, 2) == 0)
			return (func[i][1]);
		i++;
	}
	return (NULL);
}

static int	iter_func(const char *str, int ret, va_list ap)
{
	int		i;
	int		(*f)(va_list);
	char	*temp_str;

	i = 0;
	while (str[i])
	{
		if (str[i] == PS && str[i + 1])
		{
			temp_str = pf_substr(str, ++i, 1);
			if (!temp_str)
				return (0);
			f = find_token(temp_str);
			if (f != NULL)
				ret += f(ap);
			free(temp_str);
		}
		else
			ret += write_chr(str[i]);
		i++;
	}
	return (ret);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		ret;

	ret = 0;
	va_start(ap, str);
	ret = iter_func(str, ret, ap);
	va_end(ap);
	return (ret);
}
