/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_rays.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 13:15:04 by gialexan          #+#    #+#             */
/*   Updated: 2023/07/21 19:16:42 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    render_rays(t_cub3d *cub3d)
{
    int i;

    i = 0;
    while (i < NUM_RAYS)
    {
        draw_line(&cub3d->image, (t_line){
                                    cub3d->player.x,
                                    cub3d->player.y,
                                    cub3d->rays[i].wall_hit_x,
                                    cub3d->rays[i].wall_hit_y,
                                    RED_PIXEL});
        i += 20;
    }
}
