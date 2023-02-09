/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   add_back.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/19 11:59:41 by lvan-bus      #+#    #+#                 */
/*   Updated: 2023/01/19 11:59:42 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	add_back(t_node **head, int content)
{
	t_node	*current;

	current = *head;
	while (current->next != NULL)
		current = current->next;
	current->next = (t_node *) malloc(sizeof(t_node));
	if (!current->next)
		return (0);
	current->next->content = content;
	current->next->next = NULL;
	(*head)->size++;
	return (1);
}
