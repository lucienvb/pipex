/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_num_check.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/19 11:59:06 by lvan-bus      #+#    #+#                 */
/*   Updated: 2023/01/19 11:59:08 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	error_num_check(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[0] == '-' && str[i] == '-')
			i++;
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}
