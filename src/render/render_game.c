/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 13:17:39 by gialexan          #+#    #+#             */
/*   Updated: 2023/07/21 11:09:43 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	render_game(t_cub3d *cub3d)
{
    if (cub3d->window.mlx_win == NULL)
        return (1);


    //Minimap Display.
    render_map(cub3d);
    cast_rays(cub3d);
    render_rays(cub3d);
    render_player(cub3d);

    mlx_put_image_to_window(cub3d->window.mlx_ptr, cub3d->window.mlx_win, cub3d->image.mlx_img, 0, 0);
    return (0);
}
