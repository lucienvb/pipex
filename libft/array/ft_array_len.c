/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_array_len.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/14 16:08:11 by lvan-bus      #+#    #+#                 */
/*   Updated: 2023/02/14 16:08:12 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_array_len(char **array)
{
	size_t	len;

	if (!array || !array[0])
		return (0);
	len = 0;
	while (array[len])
		len++;
	return (len);
}
