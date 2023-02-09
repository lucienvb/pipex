/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_limit_check.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/19 11:58:53 by lvan-bus      #+#    #+#                 */
/*   Updated: 2023/01/20 15:30:44 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "stdio.h"

size_t	error_limit_check(char **argv)
{
	int		num;
	size_t	i;

	i = 0;
	while (argv[i])
	{
		if (ft_atoi_with_overflow(argv[i], &num) == 0)
		{
			ft_printf("Error");
			exit(0);
		}
		if (num < INT_MIN || num > INT_MAX)
			return (0);
		i++;
	}
	return (error_double_check(argv));
}
