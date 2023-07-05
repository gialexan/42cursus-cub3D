/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 19:07:02 by gialexan          #+#    #+#             */
/*   Updated: 2022/06/20 21:28:21 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char	*aux;
	unsigned char	*dst;

	dst = dest;
	aux = (unsigned char *)src;
	if (src < dest)
		return (ft_memcpy(dest, src, len));
	while (len--)
		*(dst++) = *(aux++);
	return (dest);
}
