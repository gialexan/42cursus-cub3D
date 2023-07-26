/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_wall.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:03:58 by gialexan          #+#    #+#             */
/*   Updated: 2023/07/26 12:01:11 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int    calculate_texture_offset_x(t_rays *ray)
{
    if (ray->was_hit_vertical)
        return((int)ray->wall_hit_y % TEXTURE_HEIGHT);
    return((int)ray->wall_hit_x % TEXTURE_WIDTH);  
}

static int  calculate_texture_offset_y(int wall_strip_height, int y)
{
    int dist_from_top;

    dist_from_top = y + (wall_strip_height / 2) - (WINDOW_HEIGHT / 2);
    return (dist_from_top * ((float)TEXTURE_HEIGHT / wall_strip_height));
}

void    generate_wall(t_cub3d *cub3d, t_wall *wall, int x)
{
    int y;
    int texture_num;
    int texture_offset_x;
    int texture_offset_y;

    y = wall->wall_top_pixel;
    texture_num = cub3d->rays[x].wall_hit_content - 1;
    texture_offset_x = calculate_texture_offset_x(&cub3d->rays[x]);
    while (++y < wall->wall_bottom_pixel)
    {
        texture_offset_y = calculate_texture_offset_y(wall->wall_strip_height, y);
        wall->color = cub3d->textures[texture_num][(TEXTURE_WIDTH * texture_offset_y) + texture_offset_x];
        cub3d->color_buffer[(WINDOW_WIDTH * y) + x] = wall->color;
    }
}
