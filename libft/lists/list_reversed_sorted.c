/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list_reversed_sorted.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/19 12:00:08 by lvan-bus      #+#    #+#                 */
/*   Updated: 2023/01/19 12:00:11 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	list_reversed_sorted(t_node *stack)
{
	if (!stack || stack->size == 1)
		return (0);
	while (stack->next != NULL)
	{
		if (stack->content < stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}
