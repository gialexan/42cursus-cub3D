/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical_intersect.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 14:39:30 by gialexan          #+#    #+#             */
/*   Updated: 2023/07/18 18:10:08 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static float   calculate_vert_x_step_increment(t_raydir *raydir);
static float   find_x_vertical_intersection(t_cub3d *cub3d, t_raydir *raydir);
static float   calculate_vert_y_step_increment(t_raydir *raydir, float angle);
static float   find_y_vertical_intersection(t_cub3d *cub3d, t_intersection *vert, float angle);

t_intersection  vertical_intersection(t_cub3d *cub3d, t_raydir *raydir, float ray_angle)
{
    t_intersection vert;

    vert.ray_hit_distance = INT_MAX;

    // Find the x-coordinate of the closest horizontal grid intersection
    vert.x_intercept = find_x_vertical_intersection(cub3d, raydir);

    // Find the y-coordinate of the closest horizontal grid intersection
    vert.y_intercept = find_y_vertical_intersection(cub3d, &vert, ray_angle);

    // Calculate the increment xstep and ystep
    vert.x_step = calculate_vert_x_step_increment(raydir);
    vert.y_step = calculate_vert_y_step_increment(raydir, ray_angle);

    // Increment xstep and ystep until we find a wall
    increment_xy_steps_find_wall(cub3d, &vert, raydir);
    return (vert);
}

static float   find_x_vertical_intersection(t_cub3d *cub3d, t_raydir *raydir)
{
    float   x_intercept;

    x_intercept = floor(cub3d->ppl.x / TILE_SIZE) * TILE_SIZE;
    if (raydir->is_ray_facing_right)
        x_intercept += TILE_SIZE;
    return (x_intercept);
}

static float   find_y_vertical_intersection(t_cub3d *cub3d, t_intersection *vert, float angle)
{
    return (cub3d->ppl.y + (vert->x_intercept - cub3d->ppl.x) * tan(angle));
}

static float calculate_vert_x_step_increment(t_raydir *raydir)
{
    float x_step;

    x_step = TILE_SIZE;
    if (raydir->is_ray_facing_left)
        x_step *= -1;
    return (x_step);
}

static float   calculate_vert_y_step_increment(t_raydir *raydir, float angle)
{
    float y_step;

    y_step = TILE_SIZE * tan(angle);
    if ((raydir->is_ray_facing_up && y_step > 0) || (raydir->is_ray_facing_down && y_step < 0))
        y_step *= -1;
    return (y_step);
}