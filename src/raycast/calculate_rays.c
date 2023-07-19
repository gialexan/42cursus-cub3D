/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_rays.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:09:57 by gialexan          #+#    #+#             */
/*   Updated: 2023/07/19 18:39:27 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#include <float.h>
#include <limits.h>

static t_bool  is_inside_map(float x, float y);
static float   distance_between_points(float x1, float y1, float x2, float y2);
static void    set_wall_hit(t_cub3d *cub3d, t_wall *wall, t_intersection *intersect);
static void    set_to_check(t_wall *wall, t_intersection *intersect, t_raydir *raydir, t_bool is_horz);

void    increment_xy_steps_find_wall(t_cub3d *cub3d, t_intersection *intersect, t_raydir *raydir, t_bool is_horz)
{
    t_wall wall;

    intersect->ray_hit_distance = FLT_MAX;
    wall.next_touch_x = intersect->x_intercept;
    wall.next_touch_y = intersect->y_intercept;
    while (is_inside_map(wall.next_touch_x, wall.next_touch_y))
    {
        set_to_check(&wall, intersect, raydir, is_horz);
        if (map_has_wall_at(wall.x_to_check, wall.y_to_check))
        {
            set_wall_hit(cub3d, &wall, intersect);
            break;
        }
        wall.next_touch_x += intersect->x_step;
        wall.next_touch_y += intersect->y_step;
    }
}

static void    set_wall_hit(t_cub3d *cub3d, t_wall *wall, t_intersection *intersect)
{
    intersect->found_wall_hit = TRUE;
    intersect->wall_hit_x = wall->next_touch_x;
    intersect->wall_hit_y = wall->next_touch_y;
    
    double y_to_check_floor = floor(wall->y_to_check / TILE_SIZE);
    double x_to_check_floor = floor(wall->x_to_check / TILE_SIZE);

    if (y_to_check_floor >= 0 && y_to_check_floor < WINDOW_HEIGHT / TILE_SIZE &&
        x_to_check_floor >= 0 && x_to_check_floor < WINDOW_WIDTH / TILE_SIZE)
        {
        intersect->wall_content = cub3d->map[(int)y_to_check_floor][(int)x_to_check_floor];
    } else {
        // Trate casos onde o ponto está fora dos limites do mapa para evitar segfaults.
        intersect->wall_content = 0; // Ou outro valor adequado ao seu contexto.
    }
    
    // intersect->wall_content = cub3d->map[(int)floor(wall->y_to_check / TILE_SIZE)]
    //                                     [(int)floor(wall->x_to_check / TILE_SIZE)];
    intersect->ray_hit_distance = distance_between_points(
                            cub3d->player.x,
                            cub3d->player.y,
                            intersect->wall_hit_x,
                            intersect->wall_hit_y);
}

static void    set_to_check(t_wall *wall, t_intersection *intersect, t_raydir *raydir, t_bool is_horz)
{
    wall->x_to_check = wall->next_touch_x;
    wall->y_to_check = wall->next_touch_y;
    if (is_horz)
    {
        if (raydir->is_raydir_up)
            wall->y_to_check -= 1;
    }
    else
    {
        if (raydir->is_raydir_left)
            wall->x_to_check -= 1;
    }
}

static float distance_between_points(float x1, float y1, float x2, float y2)
{
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

static t_bool  is_inside_map(float x, float y)
{
    return ((x >= 0 && x <= WINDOW_WIDTH) 
        && (y >= 0 && y <= WINDOW_HEIGHT));
}