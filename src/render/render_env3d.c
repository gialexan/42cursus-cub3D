/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_env3d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 16:49:04 by gialexan          #+#    #+#             */
/*   Updated: 2023/08/08 12:26:12 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	clear_env(t_cub3d *cub3d);
static void	render_env(t_cub3d *cub3d);

void	render_env3d(t_cub3d *cub3d)
{
	render_env(cub3d);
	clear_env(cub3d);
}

static void	render_env(t_cub3d *cub3d)
{
	int	x;
	int	y;
	int	arr_pos;
	int	minimap_width;
	int	minimap_height;

	x = -1;
	minimap_width = (cub3d->window.widht * MINIMAP_SCALE_FACTOR);
	minimap_height = (cub3d->window.height * MINIMAP_SCALE_FACTOR);
	while (++x < cub3d->window.widht)
	{
		y = -1;
		while (++y < cub3d->window.height)
		{
			if (x >= minimap_width || y >= minimap_height)
			{
				arr_pos = (cub3d->window.widht * y) + x;
				draw_pixel(&cub3d->image, x, y, cub3d->color_buffer[arr_pos]);
			}
		}
	}
}

static void	clear_env(t_cub3d *cub3d)
{
	int	x;
	int	y;

	x = -1;
	while (++x < cub3d->window.widht)
	{
		y = -1;
		while (++y < cub3d->window.height)
			cub3d->color_buffer[(cub3d->window.widht * y) + x] = BLACK_PIXEL;
	}
}
