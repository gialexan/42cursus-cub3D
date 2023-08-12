/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 16:30:59 by gialexan          #+#    #+#             */
/*   Updated: 2023/08/11 08:35:10 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**read_map(int fd)
{
	char	*tmp;
	char	*line;
	char	**map;
	char	*map_tmp;

	map_tmp = ft_strdup("");
	while (1)
	{
		line = ft_get_next_line(fd);
		if (!line)
			break ;
		tmp = map_tmp;
		map_tmp = ft_strjoin(tmp, line);
		ft_free((void *)&line);
		ft_free((void *)&tmp);
	}
	map = ft_split(map_tmp, '\n');
	ft_free((void *)&map_tmp);
	close (fd);
	return (map);
}