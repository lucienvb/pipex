/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list_size.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/19 12:00:20 by lvan-bus      #+#    #+#                 */
/*   Updated: 2023/01/19 12:00:21 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	list_size(t_node *stack)
{
	int	size;

	size = 0;
	while (stack != NULL)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}
