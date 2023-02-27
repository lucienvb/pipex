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

char	*ft_strdup(char *s, int free_s)
{
	static char	*dup;
	char		*temp;
	int			strsize;

	strsize = ft_strlen(s) + 1;
	dup = malloc(strsize * sizeof(char));
	if (!dup)
		return (0);
	temp = dup;
	while (*s)
	{
		*temp = *s;
		temp++;
		s++;
	}
	if (free_s)
		free(s);
	*temp = '\0';
	return (dup);
}
