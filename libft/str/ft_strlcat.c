/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/03 14:55:42 by lvan-bus      #+#    #+#                 */
/*   Updated: 2022/12/08 14:55:03 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	count;
	size_t	len_dst;
	size_t	len_src;

	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	count = 0;
	i = 0;
	if (len_dst >= dstsize)
		return (len_src + dstsize);
	while (dst[i] && i < (dstsize - 1))
		i++;
	while (src[count] && i < (dstsize - 1))
	{
		dst[i] = src[count];
		i++;
		count++;
	}
	dst[i] = '\0';
	return (len_dst + len_src);
}
