/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 17:51:56 by gialexan          #+#    #+#             */
/*   Updated: 2023/08/01 12:23:20 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ENV3D_H
#define ENV3D_H

typedef struct s_cub3d t_cub3d;

typedef struct s_wall
{
    int         wall_height;
    int         wall_top_pixel;
    int         wall_bottom_pixel;
}   t_wall;

void    generate3d_env(t_cub3d *cub3d);
void    generate_wall(t_cub3d *cub3d, t_wall *wall, int x);
void    generate_ceil(t_cub3d *cub3d, int wall_top_pixel, int x);
void    generate_floor(t_cub3d *cub3d, int wall_bottom_pixel, int x);

#endif