/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 13:49:48 by gialexan          #+#    #+#             */
/*   Updated: 2023/08/01 10:20:15 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    init_window(t_window *window)
{
    window->mlx_ptr = mlx_init();
	window->mlx_win = mlx_new_window(window->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "cub3D");
    window->widht = (MAP_NUM_COLS * TILE_SIZE);
    window->height = (MAP_NUM_ROWS * TILE_SIZE);
}

void    destroy_window(t_window *window)
{
    mlx_destroy_window(window->mlx_ptr, window->mlx_win);
}

void    destroy_display(t_window *window)
{
    mlx_destroy_display(window->mlx_ptr);
    free(window->mlx_ptr);
}
