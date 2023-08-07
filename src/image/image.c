/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 11:30:16 by gialexan          #+#    #+#             */
/*   Updated: 2023/08/07 09:27:18 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//TODO: Verificar ponteiro da imagem.
void    create_image(t_cub3d *cub3d)
{
    cub3d->image.img_ptr = mlx_new_image(cub3d->window.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	cub3d->image.addr = mlx_get_data_addr(cub3d->image.img_ptr, &cub3d->image.bpp, &cub3d->image.line_len, &cub3d->image.endian);
}

void    put_image_to_window(t_window *window, t_image *image)
{
    mlx_put_image_to_window(window->mlx_ptr, window->mlx_win, image->img_ptr, 0, 0);
}

void    destroy_image(t_window *window, t_image *image)
{
    mlx_destroy_image(window->mlx_ptr, image->img_ptr);
}
