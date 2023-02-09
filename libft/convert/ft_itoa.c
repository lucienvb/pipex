/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/03 14:44:08 by lvan-bus      #+#    #+#                 */
/*   Updated: 2022/12/08 14:54:20 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "../libft.h"

static int	numlen(long n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		i++;
		n = n * -1;
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*p;
	long	nb;
	int		i;

	nb = n;
	i = numlen(nb) - 1;
	p = malloc((i + 2) * sizeof(char));
	if (!p)
		return (0);
	if (nb == 0)
		p[0] = '0';
	else if (nb < 0)
	{
		nb = nb * -1;
		p[0] = '-';
	}
	p[i + 1] = '\0';
	while (nb > 0 && i >= 0)
	{
		p[i--] = (nb % 10) + '0';
		nb = nb / 10;
	}
	return (p);
}
