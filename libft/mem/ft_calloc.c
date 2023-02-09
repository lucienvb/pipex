/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/03 14:42:43 by lvan-bus      #+#    #+#                 */
/*   Updated: 2022/12/08 14:54:04 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "../libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	*p;

	p = malloc (count * size);
	if (!p)
		return (0);
	ft_bzero(p, count * size);
	return (p);
}
