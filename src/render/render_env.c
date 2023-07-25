/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 16:49:04 by gialexan          #+#    #+#             */
/*   Updated: 2023/07/25 16:57:40 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void render_env(t_cub3d *cub3d)
{
    int x;
    int y;
    int arr_pos;

    y = -1;
    while (++y < WINDOW_HEIGHT)
    {
        x = -1;
        while (++x < WINDOW_WIDTH)
        {
            if (x >= (int)(WINDOW_WIDTH * MINIMAP_SCALE_FACTOR) ||
                y >= (int)(WINDOW_HEIGHT * MINIMAP_SCALE_FACTOR))
            {
                arr_pos = (WINDOW_WIDTH * y) + x;
                draw_pixel(&cub3d->image, x, y, cub3d->color_buffer[arr_pos]);
            }
        }
    }
}
