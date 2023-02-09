/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_str.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <lvan-bus@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/10 12:22:38 by lvan-bus      #+#    #+#                 */
/*   Updated: 2023/01/10 12:22:39 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	str_toupper(char *s)
{
	while (*s)
	{
		if (*s >= 'a' && *s <= 'z')
			*s -= 32;
		s++;
	}
}

int	pf_strlen(const char *str)
{
	int	index;

	index = 0;
	while (str[index])
		index++;
	return (index);
}

char	*pf_strdup(const char *s1)
{
	static char	*dup;
	char		*temp;
	int			strsize;

	strsize = pf_strlen(s1);
	dup = malloc((strsize + 1) * sizeof(char));
	if (!dup)
		return (0);
	temp = dup;
	while (*s1)
	{
		*temp = *s1;
		temp++;
		s1++;
	}
	temp[strsize] = '\0';
	return (dup);
}

int	pf_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	str1 = (unsigned char *) s1;
	str2 = (unsigned char *) s2;
	if (n < 1)
		return (0);
	i = 0;
	if (!str1[i] || !str2[i])
		return (str1[i] - str2[i]);
	while (i < n && str1[i] && str2[i])
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	if ((!str1[i] || !str2[i]) && i < n)
		return (str1[i] - str2[i]);
	return (0);
}

char	*pf_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	len_str;
	size_t	var;

	if (!s)
		return (NULL);
	len_str = pf_strlen(s);
	var = len_str - start;
	if ((size_t) start >= len_str)
		return (pf_strdup(""));
	if (len > var)
		len = var;
	p = malloc((len + 1) * sizeof(char));
	if (!p)
		return (NULL);
	pf_memcpy(p, (char *) &(s[start]), len);
	p[len] = '\0';
	return (p);
}
