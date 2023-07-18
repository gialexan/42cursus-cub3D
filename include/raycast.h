/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 14:48:45 by gialexan          #+#    #+#             */
/*   Updated: 2023/07/18 18:38:55 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef RAYCAST_h
#define RAYCAST_H

# include "libft.h"

# define PI 3.14159265
# define TWO_PI 6.28318530
# define HALF_PI (PI / 2)

# define TILE_SIZE 64
# define MAP_NUM_ROWS 13
# define MAP_NUM_COLS 20

# define WINDOW_WIDTH (MAP_NUM_COLS * TILE_SIZE)
# define WINDOW_HEIGHT (MAP_NUM_ROWS * TILE_SIZE)

# define NUM_RAYS WINDOW_WIDTH
# define MINIMAP_SCALE_FACTOR 0.3

# define FOV_ANGLE (60 * (PI / 180))

typedef struct s_raydir
{
    t_bool  is_ray_facing_up;
    t_bool  is_ray_facing_down;
    t_bool  is_ray_facing_left;
    t_bool  is_ray_facing_right;
}   t_raydir;

typedef struct s_intersection
{
    float   x_step;
    float   y_step;
    float   wall_hit_y;
    float   wall_hit_x;
    float   y_intercept;
    float   x_intercept;
    float   ray_hit_distance;
    t_bool  found_wall_hit;
    int     wall_content;
}   t_intersection;

typedef struct s_ray
{
    float       ray_angle;
    float       wall_hit_x;
    float       wall_hit_y;
    float       distance;
    t_raydir    ray_dir;
    t_bool      was_hit_vertical;
    t_bool      wall_hit_content;
    int         color;
}   t_ray;

void                cast_rays(t_cub3d *cub3d);
int                 map_has_wall_at(float x, float y);
t_raydir            define_rays_direction(float angle);
t_intersection      vertical_intersection(t_cub3d *cub3d, t_raydir *raydir, float ray_angle);
t_intersection      horizontal_intersection(t_cub3d *cub3d, t_raydir *raydir, float ray_angle);
void                set_horz_rays(t_cub3d *cub3d, t_intersection *horz, int strip_id, float angle);
void                set_vert_rays(t_cub3d *cub3d, t_intersection *vert, int strip_id, float angle);
void                increment_xy_steps_find_wall(t_player *ppl, t_intersection *intersec, t_raydir *raydir);

#endif