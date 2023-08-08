/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 11:30:16 by gialexan          #+#    #+#             */
/*   Updated: 2023/08/08 08:57:13 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    create_image(t_cub3d *cub3d)
{
    cub3d->image.img_ptr = mlx_new_image(cub3d->window.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
    if (!cub3d->image.img_ptr)
        cub3d_error(cub3d, MLX_IMAGE_ERROR, MLX_IMAGE_MSG);
	cub3d->image.addr = mlx_get_data_addr(cub3d->image.img_ptr, &cub3d->image.bpp, &cub3d->image.line_len, &cub3d->image.endian);
}

void    destroy_image(t_window *window, t_image *image)
{
    mlx_destroy_image(window->mlx_ptr, image->img_ptr);
}
