/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 13:17:39 by gialexan          #+#    #+#             */
/*   Updated: 2023/07/25 20:24:45 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	render_game(t_cub3d *cub3d)
{
    if (cub3d->window.mlx_win == NULL)
        return (1);

    if (cub3d->color_buffer == NULL)
        cub3d->color_buffer = malloc((WINDOW_WIDTH * WINDOW_HEIGHT) * sizeof(int));
    if (cub3d->wall_texture == NULL)
    {
        cub3d->wall_texture = malloc((TEXTURE_WIDTH * TEXTURE_HEIGHT) * sizeof(int));
        for (int x = 0; x < TEXTURE_WIDTH; x++)
        {
            for (int y = 0; y < TEXTURE_HEIGHT; y++)
                cub3d->wall_texture[TEXTURE_WIDTH * y + x] = (x % 8  && y % 8) ? 0xFF0000FF : 0xFF000000;
        }
    }


    cast_rays(cub3d);
    generate3d_env(cub3d);

    render_map(cub3d);
    render_env(cub3d);
    render_rays(cub3d);
    render_player(cub3d);

    clear_env(cub3d);

    mlx_put_image_to_window(cub3d->window.mlx_ptr, cub3d->window.mlx_win, cub3d->image.mlx_img, 0, 0);
    return (0);
}
