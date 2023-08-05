/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 12:56:59 by gialexan          #+#    #+#             */
/*   Updated: 2023/08/05 16:19:43 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		i;
	char	x;

	x = c;
	i = ft_strlen(str);
	while (i >= 0)
	{
		if (str[i] == x)
			return ((char *)str + i);
		i--;
	}
	return (NULL);
}
