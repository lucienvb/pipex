/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/03 14:54:59 by lvan-bus      #+#    #+#                 */
/*   Updated: 2022/12/08 14:57:58 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "../libft.h"

char	*ft_strdup(const char *s1)
{
	static char	*dup;
	char		*temp;
	int			strsize;

	strsize = ft_strlen(s1) + 1;
	dup = malloc(strsize * sizeof(char));
	if (!dup)
		return (0);
	temp = dup;
	while (*s1)
	{
		*temp = *s1;
		temp++;
		s1++;
	}
	*temp = '\0';
	return (dup);
}
