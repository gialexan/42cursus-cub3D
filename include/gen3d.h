/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 17:51:56 by gialexan          #+#    #+#             */
/*   Updated: 2023/07/24 20:24:31 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef GEN3D_H
#define GEN3D_H

typedef struct s_cub3d t_cub3d;

typedef struct s_gen3d
{
    int     wall_top_pixel;
    int     wall_strip_height;
    int     wall_bottom_pixel;
    float   distance_proj_plane;
    float   project_wall_height;
}   t_gen3d;

void    gen3d_wall(t_cub3d *cub3d);

#endif