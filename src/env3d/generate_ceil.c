/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_ceil.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:01:24 by gialexan          #+#    #+#             */
/*   Updated: 2023/08/15 12:25:51 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	generate_ceil(t_cub3d *cub3d, int wall_top_pixel, int x)
{
	int	y;
	int	color;

	y = 0;
	color = encode_rgb(
			cub3d->color[CEIL].r,
			cub3d->color[CEIL].g,
			cub3d->color[CEIL].b);
	while (y < wall_top_pixel)
		cub3d->color_buffer[(cub3d->window.widht * y++) + x] = color;
}
