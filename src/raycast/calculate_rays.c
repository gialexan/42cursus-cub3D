/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_rays.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:09:57 by gialexan          #+#    #+#             */
/*   Updated: 2023/08/16 13:02:05 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		set_wall_hit(t_cub3d *cub3d,
					t_touch *wall, t_intersection *intersect);
static void		set_to_check(t_touch *wall, float angle, t_bool is_horz);
static float	distance_between_points(float x1, float y1, float x2, float y2);

void	calculate_xy_steps_find_wall(t_cub3d *cub3d,
	t_intersection *intersect, float angle, t_bool is_horz)
{
	t_touch	wall;

	intersect->ray_hit_distance = INT_MAX;
	wall.next_touch_x = intersect->x_intercept;
	wall.next_touch_y = intersect->y_intercept;
	while ((wall.next_touch_x >= 0 && wall.next_touch_x < cub3d->window.widht)
		&& (wall.next_touch_y >= 0 && wall.next_touch_y < cub3d->window.height))
	{
		set_to_check(&wall, angle, is_horz);
		if (map_has_wall_at(&cub3d->window,
			cub3d->map, wall.x_to_check, wall.y_to_check))
		{
			set_wall_hit(cub3d, &wall, intersect);
			break ;
		}
		wall.next_touch_x += intersect->x_step;
		wall.next_touch_y += intersect->y_step;
	}
}

static void	set_wall_hit(t_cub3d *cub3d,
	t_touch *wall, t_intersection *intersect)
{
	intersect->found_wall_hit = TRUE;
	intersect->wall_hit_x = wall->next_touch_x;
	intersect->wall_hit_y = wall->next_touch_y;
	intersect->ray_hit_distance = distance_between_points(
			cub3d->player.x,
			cub3d->player.y,
			intersect->wall_hit_x,
			intersect->wall_hit_y);
}

static void	set_to_check(t_touch *wall, float angle, t_bool is_horz)
{
	wall->x_to_check = wall->next_touch_x;
	wall->y_to_check = wall->next_touch_y;
	if (is_horz)
	{
		if (is_raydir_up(angle) && is_horz)
			wall->y_to_check -= 1;
	}
	else
	{
		if (is_raydir_left(angle))
			wall->x_to_check -= 1;
	}
}

static float	distance_between_points(float x1, float y1, float x2, float y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}
