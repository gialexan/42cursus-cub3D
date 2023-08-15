/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flush_gnl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 10:44:17 by gialexan          #+#    #+#             */
/*   Updated: 2023/08/15 11:22:03 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    flush_gnl(int fd)
{
    char *line;

    while (1)
	{
		line = gnl(fd);
		if (!line)
			break ;
		free(line);
	}
    line = NULL;
}