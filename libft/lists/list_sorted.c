/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list_sorted.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/19 12:00:29 by lvan-bus      #+#    #+#                 */
/*   Updated: 2023/01/19 12:00:31 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	list_sorted(t_node *stack)
{
	t_node	*head;

	head = stack;
	if (!stack)
		return (0);
	while (stack->next != NULL)
	{
		if (stack->content > stack->next->content)
			return (0);
		stack = stack->next;
	}
	stack = head;
	return (1);
}
