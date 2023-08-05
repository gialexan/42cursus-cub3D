/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 12:03:22 by gialexan          #+#    #+#             */
/*   Updated: 2023/08/05 10:33:46 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CUB3D_H
#define CUB3D_H

# include <mlx.h>
# include <math.h>
# include <float.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

# include "draw.h"
# include "libft.h"
# include "env3d.h"
# include "image.h"
# include "player.h"
# include "render.h"
# include "window.h"
# include "raycast.h"
# include "texture.h"
# include "constants.h"

typedef struct s_color
{
    int    floor_r;
    int    floor_g;
    int    floor_b;
    int    ceil_r;
    int    ceil_g;
    int    ceil_b;
}    t_color;

typedef struct  s_map
{
    int     **map;
    char    *no_path;
    char    *so_path;
    char    *we_path;
    char    *ea_path;
    t_color     color;
    t_compass   player_course;
}   t_map;

typedef struct s_cub3d
{
    t_rays      rays[NUM_RAYS];
    t_window    window;
    t_player    player;
    t_image     image;
    t_map       map;
    int         *color_buffer;
    t_texture   textures[4];
}   t_cub3d;

t_bool  map_has_wall_at(float x, float y);
void    cub3d_error(t_cub3d *cub3d, int errnum, char *msg);

#endif