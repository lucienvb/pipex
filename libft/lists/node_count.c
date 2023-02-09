/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   node_count.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/19 12:00:51 by lvan-bus      #+#    #+#                 */
/*   Updated: 2023/01/19 12:00:52 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	node_count(t_node *stack)
{
	size_t	i;

	i = 0;
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}
