/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_ceil.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:01:24 by gialexan          #+#    #+#             */
/*   Updated: 2023/08/12 19:45:23 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	generate_ceil(t_cub3d *cub3d, int wall_top_pixel, int x)
{
	int	y;
	int	color;

	y = 0;
	color = encode_rgb(
			cub3d->map.ceil.r,
			cub3d->map.ceil.g,
			cub3d->map.ceil.b);
	while (y < wall_top_pixel)
		cub3d->color_buffer[(cub3d->window.widht * y++) + x] = color;
}
