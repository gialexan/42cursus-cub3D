/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_rays.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 13:15:04 by gialexan          #+#    #+#             */
/*   Updated: 2023/07/24 21:02:45 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    render_rays(t_cub3d *cub3d)
{
    int i;

    i = -1;
    while (++i < NUM_RAYS)
    {
        draw_line(&cub3d->image, (t_line){
                                    MINIMAP_SCALE_FACTOR * cub3d->player.x,
                                    MINIMAP_SCALE_FACTOR * cub3d->player.y,
                                    MINIMAP_SCALE_FACTOR * cub3d->rays[i].wall_hit_x,
                                    MINIMAP_SCALE_FACTOR * cub3d->rays[i].wall_hit_y,
                                    RED_PIXEL});
    }
}
