/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 12:45:26 by gialexan          #+#    #+#             */
/*   Updated: 2023/08/16 13:11:06 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	load_texture_data(t_cub3d *cub3d, t_texture *texture);

void	load_texture(t_cub3d *cub3d)
{
	load_texture_data(cub3d, &cub3d->textures[WEST]);
	load_texture_data(cub3d, &cub3d->textures[EAST]);
	load_texture_data(cub3d, &cub3d->textures[NORTH]);
	load_texture_data(cub3d, &cub3d->textures[SOUTH]);
}

void	destroy_texture(t_window *window, t_texture *textures)
{
	int	i;

	i = -1;
	while (++i < NUM_TEXTURES)
	{
		if (textures[i].img_ptr)
			mlx_destroy_image(window->mlx_ptr, textures[i].img_ptr);
	}
}

static void	load_texture_data(t_cub3d *cub3d, t_texture *texture)
{
	texture->img_ptr = mlx_xpm_file_to_image(
			cub3d->window.mlx_ptr, texture->pathname, &texture->width, &texture->height);
	if (texture->width > TEXTURE_WIDTH || texture->width < TEXTURE_WIDTH
		|| texture->height > TEXTURE_HEIGHT || texture->height < TEXTURE_HEIGHT)
		cub3d_error(cub3d, TEXTURE_SIZE_ERROR, TEXTURE_SIZE_MSG);
	texture->addr = (int *)mlx_get_data_addr(
			texture->img_ptr,
			&texture->bpp, &texture->line_len, &texture->endian);
}
