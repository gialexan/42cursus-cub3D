/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vert_intersection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 14:46:59 by gialexan          #+#    #+#             */
/*   Updated: 2023/07/31 13:14:03 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static float    calculate_vert_x_step_increment(float angle);
static float    calculate_vert_y_step_increment(float angle);
static float    find_x_vert_intersection(float player_x, float angle);
static float    find_y_vert_intersection(float player_x, float player_y, float x_intercept, float angle);

void  vertical_intersection(t_cub3d *cub3d, t_intersection *vert, float angle)
{
    // Find the x-coordinate of the closest horizontal grid intersection
   vert->x_intercept = find_x_vert_intersection(cub3d->player.x, angle);

    // Find the y-coordinate of the closest horizontal grid intersection
    vert->y_intercept = find_y_vert_intersection(cub3d->player.x, cub3d->player.y, vert->x_intercept, angle);

    // Calculate the increment xstep and ystep
    vert->x_step = calculate_vert_x_step_increment(angle);
    vert->y_step = calculate_vert_y_step_increment(angle);

    // Increment xstep and ystep until we find a wall
    calculate_xy_steps_find_wall(cub3d, vert, angle, FALSE);
}

static float   find_x_vert_intersection(float player_x, float angle)
{
    float   x_intercept;

    x_intercept = floor(player_x / TILE_SIZE) * TILE_SIZE;
    if (is_raydir_right(angle))
        x_intercept += TILE_SIZE;
    return (x_intercept);
}


static float   find_y_vert_intersection(float player_x, float player_y, float x_intercept, float angle)
{
    return (player_y + (x_intercept - player_x) * tan(angle));
}


static float calculate_vert_x_step_increment(float angle)
{
    float x_step;

    x_step = TILE_SIZE;
    if (is_raydir_left(angle))
        x_step *= -1;
    return (x_step);
}

static float   calculate_vert_y_step_increment(float angle)
{
    float y_step;

    y_step = TILE_SIZE * tan(angle);
    if ((is_raydir_up(angle) && y_step > 0) || (is_raydir_down(angle) && y_step < 0))
        y_step *= -1;
    return (y_step);
}
