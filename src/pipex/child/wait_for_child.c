/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   wait_for_child.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/10 16:40:26 by lvan-bus      #+#    #+#                 */
/*   Updated: 2023/02/10 16:40:28 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	wait_for_child(void)
{
	int	i;

	i = 2;
	while (i)
	{
		wait(NULL);
		i--;
	}
}