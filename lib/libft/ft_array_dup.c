/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_dup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 21:27:14 by gialexan          #+#    #+#             */
/*   Updated: 2023/08/16 09:37:12 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_array_len(char	**array)
{
	int	len;

	len = -1;
	while (array[++len])
		;
	return (len);
}

char	**ft_array_dup(char **array)
{
    char    **cpy;
    int     len;

    if (!array)
        return (NULL);
    len = ft_array_len(array);
    cpy = malloc((len + 1) * sizeof(char *));
    if (!cpy)
		return (NULL);
    cpy[len] = NULL;
    while (len--)
        cpy[len] = ft_strdup(array[len]);
    return (cpy);
}
