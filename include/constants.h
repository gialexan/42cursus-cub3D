/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constants.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 09:26:24 by gialexan          #+#    #+#             */
/*   Updated: 2023/07/19 18:32:44 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CONSTANTS_H
#define CONSTANTS_H

// # define WINDOW_WIDTH 600 //colunas
// # define WINDOW_HEIGHT 300 //linhas

/*
 * 1 byte = 8 bits
 * 1 pixel = 32 bits
 * 32 bits / 8 = 4 bytes.
 * 4 bytes por pixel.
*/

# define PI 3.14159265
# define TWO_PI 6.28318530
# define HALF_PI (PI / 2)

# define FOV_ANGLE (60 * (PI / 180))

# define FPS 30
# define FRAME_TIME_LENGTH (1000 / FPS)

# define RED_PIXEL 0xFF0000
# define GREEN_PIXEL 0xFF00
# define WHITE_PIXEL 0xFFFFFF
# define BLACK_PIXEL 0x000000
# define BLUE_PIXEL 0xff0
# define YELLOW_PIXEL 0xffff32

# define TILE_SIZE 64
# define MAP_NUM_ROWS 13 //y = 12
# define MAP_NUM_COLS 20 //x = 19

# define WINDOW_WIDTH (MAP_NUM_COLS * TILE_SIZE)
# define WINDOW_HEIGHT (MAP_NUM_ROWS * TILE_SIZE)

# define MINIMAP_SCALE_FACTOR 0.3
# define NUM_RAYS WINDOW_WIDTH

//KEY EVENTS
# define KEY_ESC            0xff1b
# define KEY_LEFT_ARROW     0xff51
# define KEY_UP_ARROW       0xff52  
# define KEY_RIGHT_ARROW    0xff53
# define KEY_DOWN_ARROW     0xff54
# define KEY_A              0x0061
# define KEY_S              0x0073
# define KEY_D              0x0064
# define KEY_W              0x0077

//MASK EVENTS
# define KEY_PRESS        2
# define KEY_RELEASE      3
# define DESTROY_NOTIFY   17

# define NO_EVENT_MASK 0L
# define KEY_PRESS_MASK 1L << 0
# define KEY_RELEASE_MASK 1L << 1



#endif