/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   perror_and_exit.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/10 16:39:53 by lvan-bus      #+#    #+#                 */
/*   Updated: 2023/02/10 16:39:54 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	perror_and_exit(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}
