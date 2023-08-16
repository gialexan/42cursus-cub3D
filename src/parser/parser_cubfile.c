/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_cubfile.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 12:02:01 by gialexan          #+#    #+#             */
/*   Updated: 2023/08/16 16:38:09 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parser_cubfile(t_cub3d *cub3d)
{
	parser_texture(cub3d, &cub3d->textures[NORTH], NORTH_TEXTURE);
	parser_texture(cub3d, &cub3d->textures[SOUTH], SOUTH_TEXTURE);
	parser_texture(cub3d, &cub3d->textures[WEST], WEST_TEXTURE);
	parser_texture(cub3d, &cub3d->textures[EAST], EAST_TEXTURE);
	jump_line(cub3d);
	parser_color(cub3d, &cub3d->colors[FLOOR], FLOOR_COLOR);
	parser_color(cub3d, &cub3d->colors[CEIL], CEIL_COLOR);
	jump_line(cub3d);
	parser_map(cub3d);
}
