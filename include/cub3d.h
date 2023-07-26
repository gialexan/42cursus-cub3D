/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 12:03:22 by gialexan          #+#    #+#             */
/*   Updated: 2023/07/26 17:39:14 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CUB3D_H
#define CUB3D_H

#include <mlx.h>
#include <math.h>
#include <float.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include "env.h"
#include "draw.h"
#include "libft.h"
#include "player.h"
#include "render.h"
#include "window.h"
#include "raycast.h"
#include "constants.h"

typedef struct s_cub3d
{
    t_rays      rays[NUM_RAYS];
    t_window    window;
    t_player    player;
    t_image     image;
    int         *color_buffer;
    int         *textures[8];
    int         **map;
}   t_cub3d;

t_bool map_has_wall_at(float x, float y);

#endif