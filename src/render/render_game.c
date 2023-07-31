/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 13:17:39 by gialexan          #+#    #+#             */
/*   Updated: 2023/07/31 12:27:35 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
 * TODO: Refatorar.
*/
int	render_game(t_cub3d *cub3d)
{
    if (cub3d->window.mlx_win == NULL)
        return (1);

    if (cub3d->color_buffer == NULL)
        cub3d->color_buffer = malloc((WINDOW_WIDTH * WINDOW_HEIGHT) * sizeof(int));

    cast_rays(cub3d);
    generate3d_env(cub3d);

    //minimap display
    render_map(cub3d);
    render_rays(cub3d);
    render_player(cub3d);

    //walls display
    render_env(cub3d);
    clear_env(cub3d);

    put_image_to_window(&cub3d->window, &cub3d->image);
    return (0);
}
