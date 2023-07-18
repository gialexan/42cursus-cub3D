/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizontal_intersect.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 14:41:21 by gialexan          #+#    #+#             */
/*   Updated: 2023/07/18 18:06:39 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static float    calculate_horz_y_step_increment(t_raydir *ray_dir);
static float    calculate_horz_x_step_increment(t_raydir *ray_dir, float angle);
static float    find_y_horizontal_intersection(t_cub3d *cub3d, t_raydir *ray_dir);
static float    find_x_horizontal_intersection(t_cub3d *cub3d, t_intersection *horz, float angle);

t_intersection    horizontal_intersection(t_cub3d *cub3d, t_raydir *raydir, float ray_angle)
{
    t_intersection horz;

    horz.ray_hit_distance = INT_MAX;

    // Find the y-coordinate of the closest horizontal grid intersection
    horz.y_intercept = find_y_horizontal_intersection(cub3d, raydir);

    // Find the x-coordinate of the closest horizontal grid intersection
    horz.x_intercept = find_x_horizontal_intersection(cub3d, &horz, ray_angle);

    // Calculate the increment xstep and ystep
    horz.y_step = calculate_horz_y_step_increment(raydir);
    horz.x_step = calculate_horz_x_step_increment(raydir, ray_angle);

    // Increment xstep and ystep until we find a wall
    increment_xy_steps_find_wall(cub3d, &horz, raydir);
    return (horz);
}

static float    find_y_horizontal_intersection(t_cub3d *cub3d, t_raydir *raydir)
{
    float y_intercept;

    y_intercept = floor(cub3d->ppl.y / TILE_SIZE) * TILE_SIZE;
    if (raydir->is_ray_facing_down)
        y_intercept += TILE_SIZE;
    return (y_intercept);
}


static float   find_x_horizontal_intersection(t_cub3d *cub3d, t_intersection *horz, float angle)
{
    return (cub3d->ppl.x + (horz->y_intercept - cub3d->ppl.y) / tan(angle));
}

static float   calculate_horz_y_step_increment(t_raydir *raydir)
{
    float y_step;

    y_step = TILE_SIZE;
    if (raydir->is_ray_facing_up)
        y_step *= -1;
    return (y_step);
}

static float   calculate_horz_x_step_increment(t_raydir *raydir, float angle)
{
    float x_step;

    x_step = TILE_SIZE / tan(angle);
    if ((raydir->is_ray_facing_left && x_step > 0) || (raydir->is_ray_facing_right && x_step < 0))
        x_step *= -1;
    return (x_step);
}