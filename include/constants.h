/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constants.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 09:26:24 by gialexan          #+#    #+#             */
/*   Updated: 2023/08/08 14:56:05 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTANTS_H
# define CONSTANTS_H

/*
 * 1 byte = 8 bits
 * 1 pixel = 32 bits
 * 32 bits / 8 = 4 bytes.
 * 4 bytes por pixel.
 */

/***************************************************************************\
 * MATH DEFINE
\***************************************************************************/

# define PI              3.14159265
# define TWO_PI          6.28318530
# define HALF_PI         1.57079632
# define FOV_ANGLE       1.04719755  // (60 * (PI / 180))
# define FLOAT_MAX       3.4028234664e+38

/***************************************************************************\
 * PLAYER ANGLES
\***************************************************************************/

# define ANGLE_SOUTH     1.57079632  // (90 * (PI / 180))
# define ANGLE_WEST      3.14159265  // (180 * (PI / 180))
# define ANGLE_EAST      6.28318530  // (360 * (PI / 180))
# define ANGLE_NORTH     4.71238898  // (270 * (PI / 180))

/***************************************************************************\
 * COLORS
\***************************************************************************/

# define RED_PIXEL       0xFF0000
# define GREEN_PIXEL     0xFF00
# define WHITE_PIXEL     0xFFFFFF
# define BLACK_PIXEL     0x000000
# define BLUE_PIXEL      0xff0
# define YELLOW_PIXEL    0xffff32

/***************************************************************************\
 * TEXTURES
\***************************************************************************/

# define NUM_TEXTURES    4
# define TEXTURE_WIDTH   64
# define TEXTURE_HEIGHT  64

/***************************************************************************\
 * MAP | MINIMAP
\***************************************************************************/

# define TILE_SIZE              64
# define MAP_NUM_ROWS           10
# define MAP_NUM_COLS           20

# define WINDOW_WIDTH           1280
# define WINDOW_HEIGHT          640
# define MINIMAP_SCALE_FACTOR   0.2

/***************************************************************************\
 * ERRORS
\***************************************************************************/

# define TEXTURE_PATH_ERROR         1
# define TEXTURE_PATH_MSG "Error, texture invalid path!"

# define TEXTURE_SIZE_ERROR         2
# define TEXTURE_SIZE_MSG "Error, texture invalid size! (<Size> 64x64)"

# define TEXTURE_EXTENSION_ERROR    3
# define TEXTURE_EXTENSION_MSG "Error, invalid texture file! (<Texture>.xpm)"

# define MLX_INIT_ERROR             4
# define MLX_INIT_MSG "Error, unable to start mlx system!"

# define MLX_WINDOW_ERROR           5
# define MLX_WINDOW_MSG "Error, unable to start screen!"

# define MLX_IMAGE_ERROR            6
# define MLX_IMAGE_MSG "Error, unable to start image!"

# define COLOR_BUFFER_MALLOC_ERROR  7
# define COLOR_BUFFER_MSG "Error, unable allocating memory for color buffer"

/***************************************************************************\
 * RAYS
\***************************************************************************/

# define NUM_RAYS WINDOW_WIDTH

/***************************************************************************\
 * KEYS CODE
\***************************************************************************/

# define KEY_ESC          0xff1b
# define KEY_LEFT_ARROW   0xff51
# define KEY_UP_ARROW     0xff52
# define KEY_RIGHT_ARROW  0xff53
# define KEY_DOWN_ARROW   0xff54
# define KEY_A            0x0061
# define KEY_S            0x0073
# define KEY_D            0x0064
# define KEY_W            0x0077

/***************************************************************************\
 * OTHERS
\***************************************************************************/

# define WINDOW_NAME    "Cub3D"
# define DIST_PROJ_PLANE 1108.512573 //((WINDOW_WIDTH / 2)/tan(FOV_ANGLE / 2))

#endif