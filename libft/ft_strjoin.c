/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 19:07:26 by gialexan          #+#    #+#             */
/*   Updated: 2023/04/05 12:44:39 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*aux;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	aux = (char *) malloc((s1_len + s2_len) + 1 * sizeof(char));
	if (!aux)
		return (NULL);
	ft_strlcpy(aux, s1, s1_len + 1);
	ft_strlcpy(aux + s1_len, s2, s2_len + 1);
	return (aux);
}
