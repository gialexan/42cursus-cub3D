/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen3d_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 20:12:47 by gialexan          #+#    #+#             */
/*   Updated: 2023/07/25 14:27:29 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static float    calculate_perp_distance(t_rays *ray, t_player *player)
{
    return (ray->distance * cos(ray->ray_angle - player->rotation_angle));
}

static float    calculate_dist_project_plane(void)
{
    return ((WINDOW_WIDTH / 2) / tan(FOV_ANGLE / 2));
}

static int    projected_wall_height(float perp_distance, float dist_project_plane)
{
    return ((TILE_SIZE / perp_distance) * dist_project_plane);
}

static int    calculate_wall_top_pixel(int wall_height)
{
    int wall_top_pixel;
    
    wall_top_pixel = (WINDOW_HEIGHT / 2) - (wall_height / 2);
    if (wall_top_pixel < 0)
        return (0);
    return (wall_top_pixel);
}

static int    calculate_wall_bottom_pixel(int wall_height)
{
    int wall_bottom_pixel;

    wall_bottom_pixel = (WINDOW_HEIGHT / 2) + (wall_height / 2);
    if (wall_bottom_pixel > WINDOW_HEIGHT)
        return (WINDOW_HEIGHT);
    return (wall_bottom_pixel);
}


void    gen3d_env(t_cub3d *cub3d)
{
    int     i;
    int     y;
    t_gen3d gen3d;

    i = -1;
    while (++i < NUM_RAYS)
    {
        gen3d.wall_height = projected_wall_height(
                    calculate_perp_distance(&cub3d->rays[i], 
                                            &cub3d->player),
                    calculate_dist_project_plane());
        gen3d.wall_top_pixel = calculate_wall_top_pixel(gen3d.wall_height);
        gen3d.wall_bottom_pixel = calculate_wall_bottom_pixel(gen3d.wall_height);
        y = gen3d.wall_top_pixel;
        while (y < gen3d.wall_bottom_pixel)
        {
            if (cub3d->rays[i].was_hit_vertical)
                cub3d->color_buffer[(WINDOW_WIDTH * y) + i] = 0xFFCCCCCC;
            else
                cub3d->color_buffer[(WINDOW_WIDTH * y) + i] = 0xFFFFFFFF;
            y++;
        }
    }
}
