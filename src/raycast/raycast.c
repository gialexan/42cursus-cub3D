/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 13:44:39 by gialexan          #+#    #+#             */
/*   Updated: 2023/07/28 15:44:12 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"

static void    normalize_angle(float *angle);
static void    cast_ray(t_cub3d *cub3d, float angle, int column_id);
static void    set_rays(t_cub3d *cub3d, t_intersection *intersect, int column_id, t_bool is_vert);

void    cast_rays(t_cub3d *cub3d)
{
    int     column_id;
    float   ray_angle;

    column_id = -1;
    while (++column_id < NUM_RAYS)
    {
        ray_angle = cub3d->player.rotation_angle + atan((column_id - (NUM_RAYS / 2)) / DIST_PROJ_PLANE);
        cast_ray(cub3d, ray_angle, column_id);
    }
}

static void    cast_ray(t_cub3d *cub3d, float angle, int column_id)
{
    t_intersection  horz;
    t_intersection  vert;

    normalize_angle(&angle);
    horizontal_intersection(cub3d, &horz, angle);
    vertical_intersection(cub3d, &vert, angle);
    if (vert.ray_hit_distance < horz.ray_hit_distance)
        set_vert_rays_properties(cub3d, &vert, angle, column_id);
    else
        set_horz_rays_properties(cub3d, &horz, angle, column_id);
}

static void    normalize_angle(float *angle)
{
    *angle = remainder(*angle, TWO_PI);
    if (*angle < 0)
        *angle = TWO_PI + *angle;
}
