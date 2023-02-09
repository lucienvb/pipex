/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_parsing.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/07 14:42:25 by lvan-bus      #+#    #+#                 */
/*   Updated: 2023/02/07 14:42:27 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdbool.h>

// The function input_parsing checks 3 things:
// 1) If there are 3 arguments given
// 2) If argv[1] is "mandelbrot" or "julia"
// 3) If argv[2] is an integer between 0 and 7
bool	input_parsing(int argc, char **argv)
{
	int	overflow;

	(void)argv;
	if (argc != 3)
		return (false);
	if (!(ft_strncmp(argv[1], "mandelbrot", 11) == 0)
		&& !(ft_strncmp(argv[1], "julia", 6) == 0))
		return (false);
	if (ft_strlen(argv[2]) != 1)
		return (false);
	if (!ft_atoi_with_overflow(argv[2], &overflow))
		return (false);
	if ((ft_atoi(argv[2]) < 1) || (ft_atoi(argv[2]) > 6))
		return (false);
	return (true);
}
