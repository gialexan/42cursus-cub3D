/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 08:27:55 by gialexan          #+#    #+#             */
/*   Updated: 2023/04/09 14:46:40 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_convert_array(t_list *token)
{
	int		i;
	int		lstsize;
	char	**array;

	lstsize = ft_lstsize(token);
	array = malloc((lstsize + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	i = 0;
	while (token != NULL)
	{
		array[i] = ft_strdup(token->content);
		token = token->next;
		i++;
	}
	array[i] = NULL;
	return (array);
}
