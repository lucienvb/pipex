/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/03 14:59:40 by lvan-bus      #+#    #+#                 */
/*   Updated: 2022/12/08 14:55:14 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include "../libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	len_str;
	size_t	var;

	if (!s)
		return (NULL);
	len_str = ft_strlen(s);
	var = len_str - start;
	if ((size_t) start >= len_str)
		return (ft_strdup("", 0));
	if (len > var)
		len = var;
	p = malloc((len + 1) * sizeof(char));
	if (!p)
		return (NULL);
	ft_memcpy(p, &(s[start]), len);
	p[len] = '\0';
	return (p);
}
