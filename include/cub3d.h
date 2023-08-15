/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 12:03:22 by gialexan          #+#    #+#             */
/*   Updated: 2023/08/15 19:14:03 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <X11/X.h>
# include <string.h>


# include "mlx.h"
# include "draw.h"
# include "utils.h"
# include "color.h"
# include "libft.h"
# include "env3d.h"
# include "image.h"
# include "parser.h"
# include "player.h"
# include "render.h"
# include "window.h"
# include "raycast.h"
# include "texture.h"
# include "constants.h"

typedef struct s_cub3d
{
	int			fd;
	char		**map;
	int			map_rows;
	int			map_cols;
	char		**map_tmp;
	int			*color_buffer;
	t_window	window;
	t_player	player;
	t_image		image;
	t_rgb     	colors[2];
	t_texture	textures[4];
	t_rays		rays[NUM_RAYS];
}	t_cub3d;

/***************************************************************************\
 * MAIN.C
\***************************************************************************/

int		exit_game(t_cub3d *cub3d);

#endif