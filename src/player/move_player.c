/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 15:32:57 by gialexan          #+#    #+#             */
/*   Updated: 2023/07/18 18:18:29 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    player_direction(t_cub3d *cub3d)
{
    float new_ppl_x;
    float new_ppl_y;
    float hypotenuse;

    if (cub3d->ppl.turn_direction)
        cub3d->ppl.rotation_angle += cub3d->ppl.turn_direction * cub3d->ppl.turn_speed;
    if (cub3d->ppl.horizontal_walk)
    {
        hypotenuse = cub3d->ppl.horizontal_walk * cub3d->ppl.walk_speed;
        new_ppl_x = cub3d->ppl.x + (cos(cub3d->ppl.rotation_angle + HALF_PI) * hypotenuse);
        new_ppl_y = cub3d->ppl.y + (sin(cub3d->ppl.rotation_angle + HALF_PI) * hypotenuse);
    }
    else if (cub3d->ppl.vertical_walk)
    {
        hypotenuse = cub3d->ppl.vertical_walk * cub3d->ppl.walk_speed;
        new_ppl_x = cub3d->ppl.x + (cos(cub3d->ppl.rotation_angle) * hypotenuse);
        new_ppl_y = cub3d->ppl.y + (sin(cub3d->ppl.rotation_angle) * hypotenuse);
    }
    if (!map_has_wall_at(new_ppl_x, new_ppl_y))
    {
        cub3d->ppl.x = new_ppl_x;
        cub3d->ppl.y = new_ppl_y;
    }
}