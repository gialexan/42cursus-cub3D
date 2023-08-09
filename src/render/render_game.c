/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 13:17:39 by gialexan          #+#    #+#             */
/*   Updated: 2023/08/09 10:03:29 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	render_game(t_cub3d *cub3d)
{
	update_player(cub3d);
	cast_rays(cub3d);
	generate3d_env(cub3d);
	render_minimap(cub3d);
	render_env3d(cub3d);
	mlx_put_image_to_window(
		cub3d->window.mlx_ptr,
		cub3d->window.mlx_win, cub3d->image.img_ptr, 0, 0);
	return (0);
}
