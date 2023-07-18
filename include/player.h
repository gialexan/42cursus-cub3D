/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 15:05:47 by gialexan          #+#    #+#             */
/*   Updated: 2023/07/18 18:44:04 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PLAYER_H
#define PLAYER_H

# define TILE_SIZE 64
# define MAP_NUM_ROWS 13
# define MAP_NUM_COLS 20

# define PI 3.14159265
# define TWO_PI 6.28318530
# define HALF_PI (PI / 2)

# define WINDOW_WIDTH (MAP_NUM_COLS * TILE_SIZE)
# define WINDOW_HEIGHT (MAP_NUM_ROWS * TILE_SIZE)

/* KEY EVENTS */
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

typedef struct s_player
{
    float   x;
    float   y;
    float   width;
    float   height;
    int     vertical_walk; // -1 for back, +1 for front
    int     turn_direction; // -1 for left, +1 for right
    int     horizontal_walk; // -1 for left, +1 for right
    float   rotation_angle;
    float   walk_speed;
    float   turn_speed;
}   t_player;

void    player_setup(t_cub3d *cub3d);
void    player_direction(t_cub3d *cub3d);
int     key_up(int keycode, t_cub3d *cub3d);
int     key_down(int keycode, t_cub3d *cub3d);

#endif