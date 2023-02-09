/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_list_lowest.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/19 11:59:49 by lvan-bus      #+#    #+#                 */
/*   Updated: 2023/01/19 11:59:50 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	find_list_lowest(t_node **stack, int low)
{
	t_node	*head;

	head = *stack;
	while (*stack && (*stack)->next)
	{
		if ((*stack)->next->content < low)
			low = (*stack)->next->content;
		*stack = (*stack)->next;
	}
	*stack = head;
	return (low);
}
