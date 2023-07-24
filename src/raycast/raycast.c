/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 13:44:39 by gialexan          #+#    #+#             */
/*   Updated: 2023/07/24 17:20:08 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"

static void    normalize_angle(float *angle);
static void    cast_ray(t_cub3d *cub3d, float angle, int strip_id);
static void    define_rays_direction(t_raydir *raydir, float angle);
static void    set_rays(t_cub3d *cub3d, t_intersection *intersect, int strip_id, t_bool is_vert);

void    cast_rays(t_cub3d *cub3d)
{
    int     strip_id;
    float   ray_angle;

    strip_id = -1;
    ray_angle = cub3d->player.rotation_angle - (FOV_ANGLE / 2);
    while (++strip_id < NUM_RAYS)
    {
        cast_ray(cub3d, ray_angle, strip_id);
        ray_angle += FOV_ANGLE / NUM_RAYS;
    }
}

static void    cast_ray(t_cub3d *cub3d, float angle, int strip_id)
{
    t_intersection  horz;
    t_intersection  vert;
    t_raydir        raydir;

    normalize_angle(&angle);
    define_rays_direction(&raydir, angle);
    horizontal_intersection(cub3d, &raydir, &horz, angle);
    vertical_intersection(cub3d, &raydir, &vert, angle);
    if (vert.ray_hit_distance < horz.ray_hit_distance)
        set_vert_rays_properties(cub3d, &vert, strip_id);
    else
        set_horz_rays_properties(cub3d, &horz, strip_id);
    set_rays_common_properties(cub3d, &raydir, strip_id, angle);
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
