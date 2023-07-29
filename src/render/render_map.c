/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 13:34:17 by gialexan          #+#    #+#             */
/*   Updated: 2023/07/27 20:01:36 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    render_map(t_cub3d *cub3d)
{
    int x;
    int y;
    int tile_x;
    int tile_y;
    int tile_color;

    y = -1;
    while (++y < MAP_NUM_ROWS)
    {
        x = -1;
        while (++x < MAP_NUM_COLS)
        {
            tile_x = (x * TILE_SIZE);
            tile_y = (y * TILE_SIZE);
            tile_color = cub3d->map[y][x] != 0 ? WHITE_PIXEL : BLACK_PIXEL;
            draw_rect(&cub3d->image, (t_rect){
                                            MINIMAP_SCALE_FACTOR * tile_x,
                                            MINIMAP_SCALE_FACTOR * tile_y,
                                            MINIMAP_SCALE_FACTOR * TILE_SIZE,
                                            MINIMAP_SCALE_FACTOR * TILE_SIZE,
                                            tile_color});
        }
    }
}
