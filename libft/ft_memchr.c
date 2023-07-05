/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 15:09:40 by gialexan          #+#    #+#             */
/*   Updated: 2022/06/26 18:42:25 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	char	x;
	char	*aux;

	if (!n)
		return (0);
	x = c;
	aux = (char *)str;
	while (aux && n)
	{
		if (*aux == x)
			return ((char *)aux);
		n--;
		aux++;
	}
	return (0);
}
