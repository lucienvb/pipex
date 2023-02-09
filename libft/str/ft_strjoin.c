/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/03 14:55:22 by lvan-bus      #+#    #+#                 */
/*   Updated: 2022/12/08 14:58:02 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;
	char	*temp;
	size_t	size;

	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	p = malloc(size * sizeof(char));
	if (!p)
		return (NULL);
	temp = p;
	while (*s1)
	{
		*temp = *s1;
		temp++;
		s1++;
	}
	while (*s2)
	{
		*temp = *s2;
		temp++;
		s2++;
	}
	*temp = '\0';
	return ((char *)p);
}
