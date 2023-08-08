/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constants.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 09:26:24 by gialexan          #+#    #+#             */
/*   Updated: 2023/08/07 21:12:06 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CONSTANTS_H
#define CONSTANTS_H

/*
 * 1 byte = 8 bits
 * 1 pixel = 32 bits
 * 32 bits / 8 = 4 bytes.
 * 4 bytes por pixel.
*/

/***************************************************************************\
 * MATH DEFINE
\***************************************************************************/

# define PI 3.14159265
# define TWO_PI 6.28318530
# define HALF_PI (PI / 2)
# define FOV_ANGLE (60 * (PI / 180))
# define DIST_PROJ_PLANE ((WINDOW_WIDTH / 2) / tan(FOV_ANGLE / 2))

/***************************************************************************\
 * PLAYER ANGLE
\***************************************************************************/

# define ANGLE_SOUTH (90 * (PI / 180))
# define ANGLE_WEST (180 * (PI / 180))
# define ANGLE_EAST (360 * (PI / 180))
# define ANGLE_NORTH (270 * (PI / 180))

/***************************************************************************\
 * COLORS
\***************************************************************************/

# define RED_PIXEL 0xFF0000
# define GREEN_PIXEL 0xFF00
# define WHITE_PIXEL 0xFFFFFF
# define BLACK_PIXEL 0x000000
# define BLUE_PIXEL 0xff0
# define YELLOW_PIXEL 0xffff32

/***************************************************************************\
 * TEXTURES
\***************************************************************************/

# define NUM_TEXTURES 4
# define TEXTURE_WIDTH 64
# define TEXTURE_HEIGHT 64

/***************************************************************************\
 * MAP | MINIMAP
\***************************************************************************/

# define TILE_SIZE 64
# define MAP_NUM_ROWS 10
# define MAP_NUM_COLS 20

# define WINDOW_WIDTH (MAP_NUM_COLS * TILE_SIZE)
# define WINDOW_HEIGHT (MAP_NUM_ROWS * TILE_SIZE)
# define MINIMAP_SCALE_FACTOR 0.2

/***************************************************************************\
 * ERROR
\***************************************************************************/

# define TEXTURE_PATH_ERROR 1
# define TEXTURE_PATH_MSG "Error, texture invalid path!"

# define TEXTURE_SIZE_ERROR 2
# define TEXTURE_SIZE_MSG "Error, texture invalid size! (<Size> 64x64)"

# define TEXTURE_EXTENSION_ERROR 3
# define TEXTURE_EXTENSION_MSG "Error, invalid texture file! (<Texture>.xpm)"

# define MLX_INIT_ERROR 4
# define MLX_INIT_MSG "Error, unable to start mlx system!"

# define MLX_WINDOW_ERROR 5
# define MLX_WINDOW_MSG "Error, unable to start screen!"

# define MLX_IMAGE_ERROR 6
# define MLX_IMAGE_MSG "Error, unable to start image!"

/***************************************************************************\
 * RAYS
\***************************************************************************/

# define NUM_RAYS WINDOW_WIDTH

/***************************************************************************\
 * KEYS CODE
\***************************************************************************/

# define KEY_ESC            0xff1b
# define KEY_LEFT_ARROW     0xff51
# define KEY_UP_ARROW       0xff52  
# define KEY_RIGHT_ARROW    0xff53
# define KEY_DOWN_ARROW     0xff54
# define KEY_A              0x0061
# define KEY_S              0x0073
# define KEY_D              0x0064
# define KEY_W              0x0077

/***************************************************************************\
 * MLX MASK EVENTS
\***************************************************************************/

# define KEY_PRESS      2
# define KEY_RELEASE    3
# define DESTROY_NOTIFY 17
# define MOTION_NOTIFY  6

# define NO_EVENT_MASK 0L
# define KEY_PRESS_MASK 1L << 0
# define KEY_RELEASE_MASK 1L << 1
# define POINTER_MOTION_MASK 1L << 6

/***************************************************************************\
 * OTHERS
\***************************************************************************/

# define WINDOW_NAME "Cub3D"

#endif