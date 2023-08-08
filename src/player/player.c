/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 12:28:05 by gialexan          #+#    #+#             */
/*   Updated: 2023/08/08 10:26:12 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static float get_player_course(t_cub3d *cub3d);

void    player_setup(t_cub3d *cub3d)
{
    cub3d->player.x = WINDOW_WIDTH / 2;
    cub3d->player.y = WINDOW_HEIGHT / 2;
    cub3d->player.width = 5;
    cub3d->player.height = 5;
    cub3d->player.turn_direction = 0;
    cub3d->player.vertical_walk = 0;
    cub3d->player.horizontal_walk = 0;
    cub3d->player.rotation_angle = get_player_course(cub3d);
    cub3d->player.walk_speed = 10;
    cub3d->player.turn_speed = 5 * (PI / 180);
    cub3d->player.mouse_x = 0;
}

static  float get_player_course(t_cub3d *cub3d)
{
    t_compass course;

    course = cub3d->map.player_course;
    if (course == SOUTH)
        return (ANGLE_SOUTH);
    if (course == NORTH)
        return (ANGLE_NORTH);
    if (course == WEST)
        return (ANGLE_WEST);
    if (course == EAST)
        return (ANGLE_EAST);
    return (0);
}
