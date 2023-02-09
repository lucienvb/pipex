/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_num_check_for_2d_array.c                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/19 11:59:21 by lvan-bus      #+#    #+#                 */
/*   Updated: 2023/01/19 11:59:22 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	error_num_check_for_2d_array(char **argv)
{
	size_t	i;
	size_t	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][0] == '-' && argv[i][j] == '-')
				j++;
			if (argv[i][j] < '0' || argv[i][j] > '9')
				return (0);
			j++;
		}
		i++;
	}
	return (error_limit_check(argv));
}
