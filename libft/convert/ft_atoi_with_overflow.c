/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi_with_overflow.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/20 15:53:19 by lvan-bus      #+#    #+#                 */
/*   Updated: 2023/01/20 15:53:21 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_atoi_with_overflow(const char *str, int *result)
{
	int	i;
	int	sign;

	sign = 1;
	i = 0;
	*result = 0;
	if (!str)
		return (1);
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		*result = *result * 10 + str[i] - '0';
		if (*result < 0 && *result != INT_MIN)
			return (0);
		i++;
	}
	*result *= sign;
	return (1);
}
