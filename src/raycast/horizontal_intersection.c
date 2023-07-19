/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizontal_intersection.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 14:55:07 by gialexan          #+#    #+#             */
/*   Updated: 2023/07/19 16:10:39 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


static float   calculate_horz_y_step_increment(t_raydir *raydir);
static float   find_y_horz_intersection(t_player *ppl, t_raydir *raydir);
static float   calculate_horz_x_step_increment(t_raydir *raydir, float angle);
static float   find_x_horz_intersection(t_player *ppl, t_intersection *horz, float angle);

void    horizontal_intersection(t_cub3d *cub3d, t_raydir *raydir, t_intersection *horz, float ray_angle)
{
    // Find the y-coordinate of the closest horizontal grid intersection
    horz->y_intercept = find_y_horz_intersection(&cub3d->player, raydir);

    // Find the x-coordinate of the closest horizontal grid intersection
    horz->x_intercept = find_x_horz_intersection(&cub3d->player, horz, ray_angle);

    // Calculate the increment xstep and ystep
    horz->y_step = calculate_horz_y_step_increment(raydir);
    horz->x_step = calculate_horz_x_step_increment(raydir, ray_angle);

    // Increment xstep and ystep until we find a wall
    increment_xy_steps_find_wall(cub3d, horz, raydir, TRUE);
}

static float   find_y_horz_intersection(t_player *ppl, t_raydir *raydir)
{
    float y_intercept;
    
    y_intercept = floor(ppl->y / TILE_SIZE) * TILE_SIZE;
    if (raydir->is_raydir_down)
        y_intercept += TILE_SIZE;
    return (y_intercept);
}

static float   calculate_horz_y_step_increment(t_raydir *raydir)
{
    float y_step;

    y_step = TILE_SIZE;
    if (raydir->is_raydir_up)
        y_step *= -1;
    return (y_step);
}

static float   calculate_horz_x_step_increment(t_raydir *raydir, float angle)
{
    float x_step;

    x_step = TILE_SIZE / tan(angle);
    if ((raydir->is_raydir_left && x_step > 0) || (raydir->is_raydir_right && x_step < 0))
        x_step *= -1;
    return (x_step);
}

static float   find_x_horz_intersection(t_player *ppl, t_intersection *horz, float angle)
{
    return (ppl->x + (horz->y_intercept - ppl->y) / tan(angle));
}
