/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_wall.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:03:58 by gialexan          #+#    #+#             */
/*   Updated: 2023/07/26 10:02:17 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    generate_wall(t_cub3d *cub3d, t_wall *wall, int x)
{
    int y;
    
    y = wall->wall_top_pixel;
    if (cub3d->rays[x].was_hit_vertical)
        wall->texture_offset_x = (int)cub3d->rays[x].wall_hit_y % TEXTURE_HEIGHT;
    else
        wall->texture_offset_x = (int)cub3d->rays[x].wall_hit_x % TEXTURE_WIDTH;
    while (++y < wall->wall_bottom_pixel)
    {
        wall->dist_from_top = y + (wall->wall_strip_height / 2) - (WINDOW_HEIGHT / 2);
        wall->texture_offset_y = wall->dist_from_top * ((float)TEXTURE_HEIGHT / wall->wall_strip_height);

        wall->color = cub3d->wall_texture[(TEXTURE_WIDTH * wall->texture_offset_y) + wall->texture_offset_x];
        cub3d->color_buffer[(WINDOW_WIDTH * y) + x] = wall->color;
    }
}
