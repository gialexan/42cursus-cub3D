/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_rays.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 10:01:19 by gialexan          #+#    #+#             */
/*   Updated: 2023/07/20 10:24:09 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    set_rays_common_properties(t_cub3d *cub3d, t_raydir *raydir, int strip_id, float angle)
{
    cub3d->rays[strip_id].ray_angle = angle;
    cub3d->rays[strip_id].raydir.is_raydir_up = raydir->is_raydir_up;
    cub3d->rays[strip_id].raydir.is_raydir_left = raydir->is_raydir_left;
    cub3d->rays[strip_id].raydir.is_raydir_down = raydir->is_raydir_down;
    cub3d->rays[strip_id].raydir.is_raydir_right = raydir->is_raydir_right;
}

void    set_vert_rays_properties(t_cub3d *cub3d, t_intersection *vert, int strip_id)
{
    cub3d->rays[strip_id].was_hit_vertical = TRUE;
    cub3d->rays[strip_id].wall_hit_x = vert->wall_hit_x;
    cub3d->rays[strip_id].wall_hit_y = vert->wall_hit_y;
    cub3d->rays[strip_id].distance = vert->ray_hit_distance;
    cub3d->rays[strip_id].wall_hit_content = vert->wall_content;
}

void    set_horz_rays_properties(t_cub3d *cub3d, t_intersection *horz, int strip_id)
{
    cub3d->rays[strip_id].was_hit_vertical = FALSE;
    cub3d->rays[strip_id].wall_hit_x = horz->wall_hit_x;
    cub3d->rays[strip_id].wall_hit_y = horz->wall_hit_y;
    cub3d->rays[strip_id].distance = horz->ray_hit_distance;
    cub3d->rays[strip_id].wall_hit_content = horz->wall_content;
}