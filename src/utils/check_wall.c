/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 12:18:58 by gialexan          #+#    #+#             */
/*   Updated: 2023/08/16 16:34:09 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_bool	map_has_wall_at(t_window *window, char **map, float x, float y)
{
	int	map_index_x;
	int	map_index_y;

	if ((x < 0 || x > window->widht) || (y < 0 || y > window->height))
		return (TRUE);
	map_index_x = (int)(x / TILE_SIZE);
	map_index_y = (int)(y / TILE_SIZE);
	if (map_index_x > (int)ft_strlen(map[map_index_y]) - 1)
		return (FALSE);
	return (map[map_index_y][map_index_x] != '0');
}
