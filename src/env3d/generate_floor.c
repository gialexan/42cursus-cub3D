/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_floor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:03:16 by gialexan          #+#    #+#             */
/*   Updated: 2023/08/15 11:59:46 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	generate_floor(t_cub3d *cub3d, int wall_bottom_pixel, int x)
{
	int	y;
	int	color;

	y = wall_bottom_pixel;
	color = encode_rgb(
			cub3d->color[FLOOR].r,
			cub3d->color[FLOOR].g,
			cub3d->color[FLOOR].b);
	while (y < cub3d->window.height)
		cub3d->color_buffer[(cub3d->window.widht * y++) + x] = color;
}
