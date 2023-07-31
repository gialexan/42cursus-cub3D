/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 13:49:48 by gialexan          #+#    #+#             */
/*   Updated: 2023/07/31 17:38:07 by gialexan         ###   ########.fr       */
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
