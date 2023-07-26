/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate3d_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 20:12:47 by gialexan          #+#    #+#             */
/*   Updated: 2023/07/26 13:02:01 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static float    calculate_dist_project_plane(void);
static int      calculate_wall_top_pixel(int wall_strip_height);
static int      calculate_wall_bottom_pixel(int wall_strip_height);
static float    calculate_perp_distance(t_rays *ray, t_player *player);
static float    projected_wall_height(float perp_distance, float dist_project_plane);

void    generate3d_env(t_cub3d *cub3d)
{
    int     x;
    int     y;
    t_wall wall;

    x = -1;
    while (++x < NUM_RAYS)
    {
        wall.wall_height = projected_wall_height(
                    calculate_perp_distance(&cub3d->rays[x],
                                            &cub3d->player),
                    calculate_dist_project_plane());
        wall.wall_strip_height = (int)wall.wall_height;
        wall.wall_top_pixel = calculate_wall_top_pixel(wall.wall_strip_height);
        wall.wall_bottom_pixel = calculate_wall_bottom_pixel(wall.wall_strip_height);
        generate_ceil(cub3d, wall.wall_top_pixel, x);
        generate_wall(cub3d, &wall, x);
        generate_floor(cub3d, wall.wall_bottom_pixel, x);
    }
}

static float    projected_wall_height(float perp_distance, float dist_project_plane)
{
    return ((TILE_SIZE / perp_distance) * dist_project_plane);
}

static float    calculate_perp_distance(t_rays *ray, t_player *player)
{
    return (ray->distance * cos(ray->ray_angle - player->rotation_angle));
}

static float    calculate_dist_project_plane(void)
{
    return ((WINDOW_WIDTH / 2) / tan(FOV_ANGLE / 2));
}

static int    calculate_wall_top_pixel(int wall_strip_height)
{
    int wall_top_pixel;
    
    wall_top_pixel = (WINDOW_HEIGHT / 2) - (wall_strip_height / 2);
    if (wall_top_pixel < 0)
        return (0);
    return (wall_top_pixel);
}

static int    calculate_wall_bottom_pixel(int wall_strip_height)
{
    int wall_bottom_pixel;

    wall_bottom_pixel = (WINDOW_HEIGHT / 2) + (wall_strip_height / 2);
    if (wall_bottom_pixel > WINDOW_HEIGHT)
        return (WINDOW_HEIGHT);
    return (wall_bottom_pixel);
}
