/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical_intersection.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 14:46:59 by gialexan          #+#    #+#             */
/*   Updated: 2023/07/20 10:24:15 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static float    calculate_vert_x_step_increment(t_raydir *raydir);
static float    find_x_vert_intersection(t_player *ppl, t_raydir *raydir);
static float    calculate_vert_y_step_increment(t_raydir *raydir, float angle);
static float    find_y_vert_intersection(t_player *ppl, t_intersection *vert, float angle);

void  vertical_intersection(t_cub3d *cub3d, t_raydir *raydir, t_intersection *vert, float ray_angle)
{
    // Find the x-coordinate of the closest horizontal grid intersection
    vert->x_intercept = find_x_vert_intersection(&cub3d->player, raydir);
    
    // Find the y-coordinate of the closest horizontal grid intersection
    vert->y_intercept = find_y_vert_intersection(&cub3d->player, vert, ray_angle);
    
    // Calculate the increment xstep and ystep
    vert->x_step = calculate_vert_x_step_increment(raydir);
    vert->y_step = calculate_vert_y_step_increment(raydir, ray_angle);
    
    // Increment xstep and ystep until we find a wall
    increment_xy_steps_find_wall(cub3d, vert, raydir, FALSE);
}

static float   find_x_vert_intersection(t_player *ppl, t_raydir *raydir)
{
    float   x_intercept;

    x_intercept = floor(ppl->x / TILE_SIZE) * TILE_SIZE;
    if (raydir->is_raydir_right)
        x_intercept += TILE_SIZE;
    return (x_intercept);
}

static float calculate_vert_x_step_increment(t_raydir *raydir)
{
    float x_step;

    x_step = TILE_SIZE;
    if (raydir->is_raydir_left)
        x_step *= -1;
    return (x_step);
}

static float   calculate_vert_y_step_increment(t_raydir *raydir, float angle)
{
    float y_step;

    y_step = TILE_SIZE * tan(angle);
    if ((raydir->is_raydir_up && y_step > 0) || (raydir->is_raydir_down && y_step < 0))
        y_step *= -1;
    return (y_step);
}

static float   find_y_vert_intersection(t_player *ppl, t_intersection *vert, float angle)
{
    return (ppl->y + (vert->x_intercept - ppl->x) * tan(angle));
}
