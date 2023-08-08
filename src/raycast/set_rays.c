/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_rays.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 10:01:19 by gialexan          #+#    #+#             */
/*   Updated: 2023/08/08 12:36:16 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_vert_rays_properties(t_cub3d *cub3d,
	t_intersection *vert, float angle, int column_id)
{
	cub3d->rays[column_id].ray_angle = angle;
	cub3d->rays[column_id].was_hit_vertical = TRUE;
	cub3d->rays[column_id].wall_hit_x = vert->wall_hit_x;
	cub3d->rays[column_id].wall_hit_y = vert->wall_hit_y;
	cub3d->rays[column_id].distance = vert->ray_hit_distance;
}

void	set_horz_rays_properties(t_cub3d *cub3d,
	t_intersection *horz, float angle, int column_id)
{
	cub3d->rays[column_id].ray_angle = angle;
	cub3d->rays[column_id].was_hit_vertical = FALSE;
	cub3d->rays[column_id].wall_hit_x = horz->wall_hit_x;
	cub3d->rays[column_id].wall_hit_y = horz->wall_hit_y;
	cub3d->rays[column_id].distance = horz->ray_hit_distance;
}
