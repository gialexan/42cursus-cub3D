/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 14:28:20 by gialexan          #+#    #+#             */
/*   Updated: 2022/11/04 21:50:52 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	num_word(char const *s, char delimiter)
{
	size_t	i;
	size_t	num;

	i = 0;
	num = 0;
	while (s[i])
	{
		while (s[i] == delimiter)
			i++;
		if (s[i])
		{
			while (s[i] && s[i] != delimiter)
				i++;
			num++;
		}
	}
	return (num);
}

static size_t	len_word(char const *s, char delimiter, int i)
{
	size_t	c;

	c = 0;
	while (s[i] && s[i] != delimiter)
	{
		i++;
		c++;
	}
	return (c);
}

static char	**alloc_word(char const *str, char c)
{
	char	**tab;

	tab = (char **) malloc((num_word(str, c) + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	return (tab);
}

static char	*alloc_digit(char const *str, char c, int i)
{
	char	*tab;

	tab = (char *) malloc((len_word(str, c, i) + 1) * sizeof(char));
	if (!tab)
		return (NULL);
	return (tab);
}

char	**ft_split(char const *str, char c)
{
	size_t	i;
	size_t	j;
	size_t	w;
	char	**tab;

	i = 0;
	j = 0;
	tab = alloc_word(str, c);
	while (str[i])
	{
		w = 0;
		while (str[i] == c)
			i++;
		if (str[i])
		{
			tab[j] = alloc_digit(str, c, i);
			while (str[i] && str[i] != c)
				tab[j][w++] = str[i++];
			tab[j][w] = '\0';
			j++;
		}
	}
	tab[j] = NULL;
	return (tab);
}
