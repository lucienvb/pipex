/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_str_tolower.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/01 17:08:26 by lvan-bus      #+#    #+#                 */
/*   Updated: 2023/03/01 17:08:27 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str_tolower(const char *str)
{
	size_t	i;
	size_t	len;
	char	*new_str;

	len = ft_strlen(str);
	new_str = malloc((len + 1) * sizeof(char));
	i = 0;
	while (str[i])
	{
		new_str[i] = ft_tolower(str[i]);
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
