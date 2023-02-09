/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/03 14:56:05 by lvan-bus      #+#    #+#                 */
/*   Updated: 2022/12/08 14:55:05 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(const char *str)
{
	int	index;

	index = 0;
	while (str[index])
		index++;
	return (index);
}
