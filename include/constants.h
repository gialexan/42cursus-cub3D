/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constants.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 09:26:24 by gialexan          #+#    #+#             */
/*   Updated: 2023/08/15 14:42:05 by gialexan         ###   ########.fr       */
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

# define FLOOD_FILL_VALID_CHAR "1!@0 "
# define PLAYER_CHAR "NSWE"
# define MAP_VALID_CHAR "NSWE10 "
# define WHITE_SPACE ' '
# define STRING_LINE_BREAK "\n"
# define CHAR_LINE_BREAK '\n'
# define NULL_CHAR '\0'
# define PATHNAME_START_INDEX 3
# define COLOR_START_INDEX 2
# define NORTH_TEXTURE	"NO"
# define SOUTH_TEXTURE	"SO"
# define WEST_TEXTURE	"WE"
# define EAST_TEXTURE	"EA"
# define FLOOR_COLOR	"F"
# define CEIL_COLOR		"C"

# define MAP_EXTENSION "cub"
# define TEXTURE_EXTENSION "xpm"

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
# define GREEN_PIXEL     0xFF0000
# define WHITE_PIXEL     0xFFFFFF
# define BLACK_PIXEL     0x000000
# define BLUE_PIXEL      0xff0000
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

# define TEXTURE_FILE_ERROR         1
# define TEXTURE_FILE_MSG "could not open texture file!"

# define TEXTURE_SIZE_ERROR         2
# define TEXTURE_SIZE_MSG "invalid texture size! (<Size> 64x64)"

# define TEXTURE_EXTENSION_ERROR    3
# define TEXTURE_EXTENSION_MSG "invalid texture file! (<NameTexture>.xpm)"

# define MLX_INIT_ERROR             4
# define MLX_INIT_MSG "unable to start mlx system!"

# define MLX_WINDOW_ERROR           5
# define MLX_WINDOW_MSG "unable to start screen!"

# define MLX_IMAGE_ERROR            6
# define MLX_IMAGE_MSG "unable to start image!"

# define COLOR_BUFFER_MALLOC_ERROR  7
# define COLOR_BUFFER_MSG "unable allocating memory for color buffer!"

# define INVALID_ARGS_ERROR         8
# define INVALID_ARGS_MSG  "invalid argument! (./cub3D <Map path file>)"

# define FILE_EXTENSION_ERROR       9
# define FILE_EXTENSION_MSG "invalid map file! (<NameMap>.cub)"

# define FILE_FILE_ERROR            10
# define FILE_FILE_MSG "could not open .cub file!"

# define FILE_SETTING_ERROR         11
# define FILE_SETTING_MSG "invalid .cub file settings!"

# define FILE_EMPTY_ERROR           12
# define FILE_EMPTY_MSG ".cub file is empty!"

# define PARSER_TEXTURE_ERROR       13
# define PARSER_TEXTURE_MSG "invalid texture setting!"

# define PARSER_COLOR_ERROR         14
# define PARSER_COLOR_MSG "invalid color setting!"

# define PARSER_MAP_ERROR           15
# define PARSER_MAP_MSG "invalid map setting!"


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
# define WALL_DISTANCE 40.0
# define BUFFER 1024
# define DIST_PROJ_PLANE 1108.512573 //((WINDOW_WIDTH / 2)/tan(FOV_ANGLE / 2))

#endif