/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 13:49:48 by gialexan          #+#    #+#             */
/*   Updated: 2023/08/07 21:10:56 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    init_window(t_cub3d *cub3d)
{
    cub3d->window.mlx_ptr = mlx_init();
    if (!cub3d->window.mlx_ptr)
        cub3d_error(cub3d, MLX_INIT_ERROR, MLX_INIT_MSG);
    cub3d->window.mlx_win = mlx_new_window(cub3d->window.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_NAME);
    if (!cub3d->window.mlx_win)
        cub3d_error(cub3d, MLX_WINDOW_ERROR, MLX_WINDOW_MSG);
    cub3d->window.widht = MAP_NUM_COLS * TILE_SIZE;
    cub3d->window.height = MAP_NUM_ROWS * TILE_SIZE;
}

void    destroy_window(t_window *window)
{
    if (window->mlx_win)
        mlx_destroy_window(window->mlx_ptr, window->mlx_win);
    mlx_destroy_display(window->mlx_ptr);
    free(window->mlx_ptr);
}
