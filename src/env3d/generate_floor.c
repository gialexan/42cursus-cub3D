/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_floor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:03:16 by gialexan          #+#    #+#             */
/*   Updated: 2023/08/16 11:29:14 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	generate_floor(t_cub3d *cub3d, int wall_bottom_pixel, int x)
{
	int	y;
	int	color;

	y = wall_bottom_pixel;
	color = encode_rgb(
			cub3d->colors[FLOOR].r,
			cub3d->colors[FLOOR].g,
			cub3d->colors[FLOOR].b);
	while (y < cub3d->window.height)
		cub3d->color_buffer[(WINDOW_WIDTH * y++) + x] = color;
}
