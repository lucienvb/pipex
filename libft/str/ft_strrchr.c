/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/03 14:58:46 by lvan-bus      #+#    #+#                 */
/*   Updated: 2022/12/08 14:55:11 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	const char	*p;

	p = 0;
	while (1)
	{
		if (*s == (char)c)
			p = s;
		if (!*s)
			return ((char *)p);
		s++;
	}
}	
