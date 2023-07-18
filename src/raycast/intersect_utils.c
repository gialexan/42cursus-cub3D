/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 14:45:13 by gialexan          #+#    #+#             */
/*   Updated: 2023/07/18 18:12:51 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

const int map[MAP_NUM_ROWS][MAP_NUM_COLS] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 ,1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

int map_has_wall_at(float x, float y)
{
    int map_index_x;
    int map_index_y;

    if ((x < 0 || x > WINDOW_WIDTH) || (y < 0 || y > WINDOW_HEIGHT))
        return TRUE;
    map_index_x = floor(x / TILE_SIZE);
    map_index_y = floor(y / TILE_SIZE);
    return (map[map_index_y][map_index_x] != 0);
}

float distanceBetweenPoints(float x1, float y1, float x2, float y2)
{
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

void    increment_xy_steps_find_wall(t_cub3d *cub3d, t_intersection *intersec, t_raydir *raydir)
{
    float   y_to_check;
    float   x_to_check;
    float   next_touch_x;
    float   next_touch_y;

    next_touch_x = intersec->x_intercept;
    next_touch_y = intersec->y_intercept;
    while ((next_touch_x >= 0 && next_touch_x <= WINDOW_WIDTH) && (next_touch_y >= 0 && next_touch_y <= WINDOW_HEIGHT))
    {
        x_to_check = next_touch_x;
        y_to_check = next_touch_y;
        if (raydir->is_ray_facing_up)
            y_to_check -= 1;
        if (raydir->is_ray_facing_left)
            x_to_check -= 1;
        if (map_has_wall_at(x_to_check, y_to_check))
        {
            intersec->wall_hit_x = next_touch_x;
            intersec->wall_hit_y = next_touch_y;
            intersec->wall_content = map[(int)floor(y_to_check / TILE_SIZE)][(int)floor(x_to_check / TILE_SIZE)];
            intersec->ray_hit_distance = distanceBetweenPoints(cub3d->ppl.x, cub3d->ppl.y, intersec->wall_hit_x, intersec->wall_hit_y);
            intersec->found_wall_hit = TRUE;
            break;
        }
        next_touch_x += intersec->x_step;
        next_touch_y += intersec->y_step;
    }
}

t_raydir    define_rays_direction(float angle)
{
    t_raydir raydir;
    
    raydir.is_ray_facing_down = angle > 0 && angle < PI;
    raydir.is_ray_facing_up = !raydir.is_ray_facing_down;

    raydir.is_ray_facing_right = angle < (0.5 * PI) || angle > (1.5 * PI);
    raydir.is_ray_facing_left = !raydir.is_ray_facing_right;
    return (raydir);
}

void    set_vert_rays(t_cub3d *cub3d, t_intersection *vert, int strip_id, float angle)
{
    cub3d->rays[strip_id].ray_angle = angle;
    cub3d->rays[strip_id].was_hit_vertical = TRUE;
    cub3d->rays[strip_id].wall_hit_x = vert->wall_hit_x;
    cub3d->rays[strip_id].wall_hit_y = vert->wall_hit_y;
    cub3d->rays[strip_id].distance = vert->ray_hit_distance;
    cub3d->rays[strip_id].wall_hit_content = vert->wall_content;
}

void    set_horz_rays(t_cub3d *cub3d, t_intersection *horz, int strip_id, float angle)
{
    cub3d->rays[strip_id].ray_angle = angle;
    cub3d->rays[strip_id].was_hit_vertical = TRUE;
    cub3d->rays[strip_id].wall_hit_x = horz->wall_hit_x;
    cub3d->rays[strip_id].wall_hit_y = horz->wall_hit_y;
    cub3d->rays[strip_id].distance = horz->ray_hit_distance;
    cub3d->rays[strip_id].wall_hit_content = horz->wall_content;
}