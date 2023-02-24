/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/24 15:05:34 by lvan-bus      #+#    #+#                 */
/*   Updated: 2023/02/24 15:05:35 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_strjoin(char *s1, char *s2)
{
	char	*temp;
	size_t	size;
	int		i;
	int		j;

	size = ft_strlen(s1) + ft_strlen(s2);
	temp = malloc((size + 1) * sizeof(char));
	if (!temp)
		return (free(s1), NULL);
	i = 0;
	while (s1[i])
	{
		temp[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		temp[i + j] = s2[j];
		j++;
	}
	temp[i + j] = '\0';
	free(s1);
	return (temp);
}

char	*gnl_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (unsigned char) c)
			return ((char *)s);
		s++;
	}
	if ((unsigned char) c == '\0')
		return ((char *)s);
	return (NULL);
}

void	*gnl_memcpy(void *dst, const char *src, size_t n)
{
	char	*dest;
	char	*source;

	if (!dst && !src)
		return (0);
	dest = dst;
	source = (char *)src;
	while (n > 0)
	{
		*dest = *source;
		dest++;
		source++;
		n--;
	}
	return (dst);
}

char	*gnl_strdup(char *s1)
{
	char	*dup;
	char	*temp;
	int		strsize;

	if (!s1)
		return (NULL);
	strsize = ft_strlen(s1);
	dup = malloc((strsize + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	temp = dup;
	while (*s1)
	{
		*temp = *s1;
		temp++;
		s1++;
	}
	dup[strsize] = '\0';
	return (dup);
}

char	*gnl_substr(char *s, unsigned int start, size_t len, int free_s)
{
	char	*p;
	size_t	len_str;
	size_t	var;

	if (!s)
		return (free(s), NULL);
	len_str = ft_strlen(s);
	var = len_str - start;
	if ((size_t) start >= len_str)
	{
		free(s);
		return (gnl_strdup(""));
	}
	if (len > var)
		len = var;
	p = malloc((len + 1) * sizeof(char));
	if (!p)
		return (free(s), NULL);
	gnl_memcpy(p, &(s[start]), len);
	p[len] = '\0';
	if (free_s)
		free(s);
	return (p);
}
