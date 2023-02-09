/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   new_list.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/19 12:00:40 by lvan-bus      #+#    #+#                 */
/*   Updated: 2023/01/19 12:00:43 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_node	*new_list(t_node *stack, char **argv)
{
	t_node	*new;

	if (!argv)
		return (NULL);
	new = (t_node *) malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->content = ft_atoi(argv[1]);
	new->size = 1;
	new->next = NULL;
	new->next = stack;
	return (new);
}
