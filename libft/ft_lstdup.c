/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 22:20:13 by gialexan          #+#    #+#             */
/*   Updated: 2023/04/09 14:47:56 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*new_node(void *content, t_tk_type type)
{
	t_list	*token;

	token = malloc(sizeof(t_list));
	if (!token)
		return (NULL);
	token->content = ft_strdup(content);
	token->tk_type = type;
	token->next = NULL;
	return (token);
}

t_list	*ft_lstdup(t_list *lst)
{
	t_list	*node;
	t_list	*lstdup;

	if (!lst)
		return (NULL);
	lstdup = NULL;
	while (lst != NULL)
	{
		node = new_node(lst->content, lst->tk_type);
		ft_lstadd_back(&lstdup, node);
		lst = lst->next;
	}
	return (lstdup);
}
