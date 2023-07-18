/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 14:47:31 by gialexan          #+#    #+#             */
/*   Updated: 2023/07/18 18:07:23 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static float    normalize_angle(float angle);
static void     cast_ray(t_cub3d *cub3d, float ray_angle, int strip_id);

void    cast_rays(t_cub3d *cub3d)
{
    int     strip_id;
    float   ray_angle;

    strip_id = 0;
    ray_angle = cub3d->ppl.rotation_angle - (FOV_ANGLE / 2);
    while (strip_id < NUM_RAYS)
    {
        cast_ray(cub3d, ray_angle, strip_id);
        ray_angle += FOV_ANGLE / NUM_RAYS;
        strip_id++;
    }
}

static void    cast_ray(t_cub3d *cub3d, float ray_angle, int strip_id)
{
    t_intersection  horz;
    t_intersection  vert;
    t_raydir        raydir;

    ray_angle = normalize_angle(ray_angle);
    raydir = define_rays_direction(ray_angle);
    horz = horizontal_intersection(cub3d, &raydir, ray_angle);
    vert = vertical_intersection(cub3d, &raydir, ray_angle);
    if (vert.ray_hit_distance < horz.ray_hit_distance)
        set_vert_rays(cub3d, &vert, strip_id, ray_angle);
    else
        set_horz_rays(cub3d, &horz, strip_id, ray_angle);   
}

static float    normalize_angle(float angle)
{
    angle = remainder(angle, TWO_PI);
    if (angle < 0)
        angle = TWO_PI + angle;
    return (angle);
}
