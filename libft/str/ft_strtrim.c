/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/10 09:26:12 by lvan-bus      #+#    #+#                 */
/*   Updated: 2022/12/08 14:58:27 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "../libft.h"

static char	*trim(char const *s1, size_t start, size_t end)
{
	char	*ptr;
	char	*trim;

	ptr = malloc((end - start + 2) * sizeof(char));
	if (!ptr)
		return (NULL);
	trim = ptr;
	while (start < (end + 1))
		*trim++ = s1[start++];
	*trim = '\0';
	return ((char *)ptr);
}

static int	checkset(char const *set, char c)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	if (!s1)
		return (NULL);
	if (!set || !*s1)
		return (ft_strdup((char *) s1, 0));
	start = 0;
	end = ft_strlen(s1) - 1;
	while (s1[start] && checkset(set, s1[start]) == 1)
		start++;
	while (end != 0 && checkset(set, s1[end]) == 1)
		end--;
	if (start > end)
		return (ft_strdup("", 0));
	return (trim(s1, start, end));
}
