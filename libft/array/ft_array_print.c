/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_array.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/14 16:06:11 by lvan-bus      #+#    #+#                 */
/*   Updated: 2023/02/14 16:06:12 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_array_print(char **list)
{
	int	i;

	if (!list || list[0] == NULL)
		return ;
	i = 0;
	while (list[i])
		ft_printf("%s\n", list[i++]);
}
