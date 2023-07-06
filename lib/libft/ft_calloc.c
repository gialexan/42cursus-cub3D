/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 14:23:48 by gialexan          #+#    #+#             */
/*   Updated: 2022/06/20 19:32:09 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nbyte, size_t size)
{
	int		i;
	void	*dst;

	i = nbyte * size;
	if (!i || i / size != nbyte)
		return (NULL);
	dst = (void *) malloc(nbyte * size);
	if (!dst)
		return (NULL);
	ft_bzero(dst, (nbyte * size));
	return (dst);
}
