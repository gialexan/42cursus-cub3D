/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 13:49:48 by gialexan          #+#    #+#             */
/*   Updated: 2023/07/19 13:50:47 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    init_window(t_window *window)
{
    window->mlx_ptr = mlx_init();
	window->mlx_win = mlx_new_window(window->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "cub3D");
}

void    create_image(t_window *window, t_image *image)
{
    image->mlx_img = mlx_new_image(window->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	image->addr = mlx_get_data_addr(image->mlx_img, &image->bpp, &image->line_len, &image->endian);
}