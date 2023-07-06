/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 01:39:29 by gialexan          #+#    #+#             */
/*   Updated: 2022/06/26 16:10:05 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		len;
	char	*dup;

	len = ft_strlen(src) + 1;
	dup = (char *) malloc (len * sizeof(char));
	if (!dup)
		return (NULL);
	ft_strlcpy(dup, src, len);
	return (dup);
}
