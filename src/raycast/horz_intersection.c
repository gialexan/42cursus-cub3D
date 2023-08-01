/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horz_intersection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 14:55:07 by gialexan          #+#    #+#             */
/*   Updated: 2023/08/01 15:18:56 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static float   calculate_horz_y_step_increment(float angle);
static float   calculate_horz_x_step_increment(float angle);
static float   find_y_horz_intersection(float player_y, float angle);
static float   find_x_horz_intersection(float player_y, float player_x, float y_intercept, float angle);

void    horizontal_intersection(t_cub3d *cub3d, t_intersection *horz, float angle)
{
    // Find the y-coordinate of the closest horizontal grid intersection
    horz->y_intercept = find_y_horz_intersection(cub3d->player.y, angle);

    // Find the x-coordinate of the closest horizontal grid intersection
    horz->x_intercept = find_x_horz_intersection(cub3d->player.y, cub3d->player.x, horz->y_intercept, angle);

    // Calculate the increment xstep and ystep
    horz->y_step = calculate_horz_y_step_increment(angle);
    horz->x_step = calculate_horz_x_step_increment(angle);

    // Increment xstep and ystep until we find a wall
    calculate_xy_steps_find_wall(cub3d, horz, angle, TRUE);
}

static float   find_y_horz_intersection(float player_y, float angle)
{
    float y_intercept;
    
    y_intercept = floor(player_y / TILE_SIZE) * TILE_SIZE;
    if (is_raydir_down(angle))
        y_intercept += TILE_SIZE;
    return (y_intercept);
}

static float   find_x_horz_intersection(float player_y, float player_x, float y_intercept, float angle)
{
    return (player_x + (y_intercept - player_y) / tan(angle));
}

static float   calculate_horz_y_step_increment(float angle)
{
    float y_step;

    y_step = TILE_SIZE;
    if (is_raydir_up(angle))
        y_step *= -1;
    return (y_step);
}

static float   calculate_horz_x_step_increment(float angle)
{
    float x_step;

    x_step = TILE_SIZE / tan(angle);
    if ((is_raydir_left(angle) && x_step > 0) || (is_raydir_right(angle) && x_step < 0))
        x_step *= -1;
    return (x_step);
}
