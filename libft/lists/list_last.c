/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list_last.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/19 11:59:58 by lvan-bus      #+#    #+#                 */
/*   Updated: 2023/01/19 12:00:00 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_node	*list_last(t_node *stack)
{
	while (stack->next != NULL)
		stack = stack->next;
	return (stack);
}
