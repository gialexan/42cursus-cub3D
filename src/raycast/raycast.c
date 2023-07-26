/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 13:44:39 by gialexan          #+#    #+#             */
/*   Updated: 2023/07/26 15:44:09 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"

static void    normalize_angle(float *angle);
static void    cast_ray(t_cub3d *cub3d, float angle, int column_id);
static void    define_rays_direction(t_raydir *raydir, float angle);
static void    set_rays(t_cub3d *cub3d, t_intersection *intersect, int column_id, t_bool is_vert);

void    cast_rays(t_cub3d *cub3d)
{
    int     column_id;
    float   ray_angle;

    column_id = -1;
    while (++column_id < NUM_RAYS)
    {
        ray_angle = cub3d->player.rotation_angle + atan((column_id - NUM_RAYS / 2) / DIST_PROJ_PLANE);
        cast_ray(cub3d, ray_angle, column_id);
    }
}

static void    cast_ray(t_cub3d *cub3d, float angle, int column_id)
{
    t_intersection  horz;
    t_intersection  vert;
    t_raydir        raydir;

    normalize_angle(&angle);
    define_rays_direction(&raydir, angle);
    horizontal_intersection(cub3d, &raydir, &horz, angle);
    vertical_intersection(cub3d, &raydir, &vert, angle);
    if (vert.ray_hit_distance < horz.ray_hit_distance)
        set_vert_rays_properties(cub3d, &vert, column_id);
    else
        set_horz_rays_properties(cub3d, &horz, column_id);
    set_rays_common_properties(cub3d, &raydir, column_id, angle);
}

static void    normalize_angle(float *angle)
{
    *angle = remainder(*angle, TWO_PI);
    if (*angle < 0)
        *angle = TWO_PI + *angle;
}

static void    define_rays_direction(t_raydir *raydir, float angle)
{  
    raydir->is_raydir_down = angle > 0 && angle < PI;
    raydir->is_raydir_up = !raydir->is_raydir_down;

    raydir->is_raydir_right = angle < (0.5 * PI) || angle > (1.5 * PI);
    raydir->is_raydir_left = !raydir->is_raydir_right;
}
