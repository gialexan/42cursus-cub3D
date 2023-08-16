/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_ceil.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:01:24 by gialexan          #+#    #+#             */
/*   Updated: 2023/08/16 11:29:17 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	generate_ceil(t_cub3d *cub3d, int wall_top_pixel, int x)
{
	int	y;
	int	color;

	y = 0;
	color = encode_rgb(
			cub3d->colors[CEIL].r,
			cub3d->colors[CEIL].g,
			cub3d->colors[CEIL].b);
	while (y < wall_top_pixel)
		cub3d->color_buffer[(WINDOW_WIDTH * y++) + x] = color;
}
