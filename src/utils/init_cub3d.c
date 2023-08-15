/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cub3d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 18:39:12 by gialexan          #+#    #+#             */
/*   Updated: 2023/08/15 19:19:17 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void    init_colors(t_rgb *colors);
static void    init_textures(t_texture *textures);

void	init_cub3d(t_cub3d *cub3d)
{
	cub3d->fd = -1;
	cub3d->map_cols = -1;
	cub3d->map_rows = -1;
	cub3d->player.course = '\0';
	cub3d->player.x = -1;
	cub3d->player.y = -1;
	cub3d->map = NULL;
	cub3d->map_tmp = NULL;
	cub3d->color_buffer = NULL;
	cub3d->image.img_ptr = NULL;
	cub3d->image.addr = NULL;
	cub3d->window.mlx_ptr = NULL;
	cub3d->window.mlx_ptr = NULL;
	init_colors(cub3d->colors);
	init_textures(cub3d->textures);
}

static void    init_textures(t_texture *textures)
{
    textures[WEST].img_ptr = NULL;
	textures[EAST].img_ptr = NULL;
	textures[NORTH].img_ptr = NULL;
	textures[SOUTH].img_ptr = NULL;
	textures[WEST].addr = NULL;
	textures[EAST].addr = NULL;
	textures[NORTH].addr = NULL;
	textures[SOUTH].addr = NULL;
    ft_memset(textures[NORTH].pathname, NULL_CHAR, BUFFER);
	ft_memset(textures[SOUTH].pathname, NULL_CHAR, BUFFER);
	ft_memset(textures[WEST].pathname, NULL_CHAR, BUFFER);
	ft_memset(textures[EAST].pathname, NULL_CHAR, BUFFER);
}

static void    init_colors(t_rgb *colors)
{
    colors[CEIL].r = -1;
	colors[CEIL].g = -1;
	colors[CEIL].b = -1;
	colors[FLOOR].r = -1;
	colors[FLOOR].g = -1;
	colors[FLOOR].b = -1;
}
