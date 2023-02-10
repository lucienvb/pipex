/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/10 09:26:00 by lvan-bus      #+#    #+#                 */
/*   Updated: 2022/12/06 14:03:57 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "../libft.h"

static char	*word(char const *s, char c)
{
	char	*word;
	size_t	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	word = malloc ((i + 1) * sizeof(char));
	if (!word)
		return (NULL);
	ft_memcpy(word, s, i);
	word[i] = '\0';
	return (word);
}

size_t	word_count(char const *s, char c)
{
	size_t	count;
	size_t	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
			count++;
		while (s[i] != c && s[i])
			i++;
	}
	return (count);
}

static char	**remove_split(char **split, size_t i)
{
	while (i)
		free(split[--i]);
	free(split);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	size;
	size_t	i;

	if (!s)
		return (NULL);
	size = word_count(s, c) + 1;
	i = 0;
	split = malloc((size + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	while (*s && i < size)
	{
		while (*s == c)
			s++;
		split[i] = word(((char *) s), c);
		if (!split[i])
			return (remove_split(split, i));
		while (*s != c && *s)
			s++;
		i++;
	}
	split[i] = NULL;
	return (split);
}
