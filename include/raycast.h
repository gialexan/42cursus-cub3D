/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 13:44:49 by gialexan          #+#    #+#             */
/*   Updated: 2023/08/01 12:25:23 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef RAYCAST_H
#define RAYCAST_H

#include "libft.h"

typedef struct s_cub3d t_cub3d;

typedef struct s_touch
{
    float   y_to_check;
    float   x_to_check;
    float   next_touch_x;
    float   next_touch_y;
}   t_touch;

typedef struct s_intersection
{
    float   x_step;
    float   y_step;
    float   wall_hit_y;
    float   wall_hit_x;
    float   y_intercept;
    float   x_intercept;
    int     wall_content;
    t_bool  found_wall_hit;
    float   ray_hit_distance;
}   t_intersection;

typedef struct s_rays
{
    float       distance;
    float       ray_angle;
    float       wall_hit_x;
    float       wall_hit_y;
    t_bool      was_hit_vertical;
}   t_rays;


void    cast_rays(t_cub3d *cub3d);
t_bool	is_raydir_up(float angle);
t_bool	is_raydir_down(float angle);
t_bool	is_raydir_left(float angle);
t_bool	is_raydir_right(float angle);
void    vertical_intersection(t_cub3d *cub3d, t_intersection *vert, float angle);
void    horizontal_intersection(t_cub3d *cub3d, t_intersection *horz, float angle);
void    set_horz_rays_properties(t_cub3d *cub3d, t_intersection *horz, float angle, int column_id);
void    set_vert_rays_properties(t_cub3d *cub3d, t_intersection *vert, float angle, int column_id);
void    calculate_xy_steps_find_wall(t_cub3d *cub3d, t_intersection *intersect, float angle, t_bool is_horz);


#endif