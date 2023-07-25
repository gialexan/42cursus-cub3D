/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 13:17:39 by gialexan          #+#    #+#             */
/*   Updated: 2023/07/25 14:28:07 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void render_color_buffer(t_cub3d *cub3d, int color)
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
                //cub3d->color_buffer[arr_pos] = color;
                draw_pixel(&cub3d->image, x, y, cub3d->color_buffer[arr_pos]);
            }
        }
    }
}

void clearColorBuffer(t_cub3d *cub3d, int color) {
    for (int x = 0; x < WINDOW_WIDTH; x++)
        for (int y = 0; y < WINDOW_HEIGHT; y++)
            cub3d->color_buffer[(WINDOW_WIDTH * y) + x] = color;
}

int	render_game(t_cub3d *cub3d)
{
    if (cub3d->window.mlx_win == NULL)
        return (1);

    if (cub3d->color_buffer == NULL)
        cub3d->color_buffer = malloc((WINDOW_WIDTH * WINDOW_HEIGHT) * sizeof(int));

    //Minimap Display.
    render_map(cub3d);
    cast_rays(cub3d);
    render_rays(cub3d);
    render_player(cub3d);

    //Walls Display
    gen3d_env(cub3d);
    render_color_buffer(cub3d, 0xFF00EE30);
    clearColorBuffer(cub3d, 0xFF000000);


    mlx_put_image_to_window(cub3d->window.mlx_ptr, cub3d->window.mlx_win, cub3d->image.mlx_img, 0, 0);
    return (0);
}
