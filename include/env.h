/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 17:51:56 by gialexan          #+#    #+#             */
/*   Updated: 2023/07/26 12:56:58 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ENV_H
#define ENV_H

typedef struct s_cub3d t_cub3d;

typedef struct s_wall
{
    float   wall_height;
    int     wall_top_pixel;
    int     wall_bottom_pixel;
    int     wall_strip_height;
    int     color;
}   t_wall;


void    clear_env(t_cub3d *cub3d);
void    generate3d_env(t_cub3d *cub3d);
void    generate_wall(t_cub3d *cub3d, t_wall *wall, int x);
void    generate_ceil(t_cub3d *cub3d, int wall_top_pixel, int x);
void    generate_floor(t_cub3d *cub3d, int wall_bottom_pixel, int x);

#endif