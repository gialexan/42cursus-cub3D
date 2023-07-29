/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 16:49:04 by gialexan          #+#    #+#             */
/*   Updated: 2023/07/29 10:01:02 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void render_env(t_cub3d *cub3d)
{
    int x;
    int y;
    int arr_pos;
    int minimap_width;
    int minimap_height;

    
    x = -1;
    minimap_width = (WINDOW_WIDTH * MINIMAP_SCALE_FACTOR);
    minimap_height = (WINDOW_HEIGHT * MINIMAP_SCALE_FACTOR);
    while (++x < WINDOW_WIDTH)
    {
        y = -1;
        while (++y < WINDOW_HEIGHT)
        {
            if (x >= minimap_width || y >= minimap_height)
            {
                arr_pos = (WINDOW_WIDTH * y) + x;
                draw_pixel(&cub3d->image, x, y, cub3d->color_buffer[(WINDOW_WIDTH * y) + x]);
            }
        }
    }
}

