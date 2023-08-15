/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 16:30:59 by gialexan          #+#    #+#             */
/*   Updated: 2023/08/14 21:20:57 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	readmap_error(t_cub3d *cub3d, char *line, char *map);

char	**read_map(t_cub3d *cub3d, int fd)
{
	char	*line;
	char	*tmp;
	char	**map;
	char	*map_tmp;

	map_tmp = ft_strdup("");
	while (1)
	{
		line = gnl(fd);
		if (!line)
			break ;
		if (*line == CHAR_LINE_BREAK)
			readmap_error(cub3d, line, map_tmp);
		tmp = map_tmp;
		map_tmp = ft_strjoin(tmp, line);
		free(line);
		free(tmp);
	}
	map = ft_split(map_tmp, CHAR_LINE_BREAK);
	free(map_tmp);
	return (map);
}

static void	readmap_error(t_cub3d *cub3d, char *line, char *map)
{
	free(line);
	free(map);
	cub3d_error(cub3d, FILE_SETTING_ERROR, FILE_SETTING_MSG);
}
