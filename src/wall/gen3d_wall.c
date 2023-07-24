/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen3d_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 20:12:47 by gialexan          #+#    #+#             */
/*   Updated: 2023/07/24 20:24:21 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    gen3d_wall(t_cub3d *cub3d)
{
    for (int i = 0; i < NUM_RAYS; i++) {
        float perpDistance = cub3d->rays[i].distance * cos(cub3d->rays[i].ray_angle - cub3d->player.rotation_angle);
        float distanceProjPlane = (WINDOW_WIDTH / 2) / tan(FOV_ANGLE / 2);
        float projectedWallHeight = (TILE_SIZE / perpDistance) * distanceProjPlane;

        int wallStripHeight = (int)projectedWallHeight;

        int wallTopPixel = (WINDOW_HEIGHT / 2) - (wallStripHeight / 2);
        wallTopPixel = wallTopPixel < 0 ? 0 : wallTopPixel;

        int wallBottomPixel = (WINDOW_HEIGHT / 2) + (wallStripHeight / 2);
        wallBottomPixel = wallBottomPixel > WINDOW_HEIGHT ? WINDOW_HEIGHT : wallBottomPixel;

        // render the wall from wallTopPixel to wallBottomPixel
        for (int y = wallTopPixel; y < wallBottomPixel; y++) {
            cub3d->color_buffer[(WINDOW_WIDTH * y) + i] = cub3d->rays[i].was_hit_vertical ? 0xFFFFFFFF : 0xFFCCCCCC;
        }
    }
}