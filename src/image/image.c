/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 11:30:16 by gialexan          #+#    #+#             */
/*   Updated: 2023/07/31 11:53:28 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    create_image(t_window *window, t_image *image)
{
    image->img_ptr = mlx_new_image(window->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	image->addr = mlx_get_data_addr(image->img_ptr, &image->bpp, &image->line_len, &image->endian);
}

void    put_image_to_window(t_window *window, t_image *image)
{
    mlx_put_image_to_window(window->mlx_ptr, window->mlx_win, image->img_ptr, 0, 0);
}
