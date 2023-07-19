/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 12:28:12 by gialexan          #+#    #+#             */
/*   Updated: 2023/07/19 13:30:48 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PLAYER_H
#define PLAYER_H

typedef struct s_cub3d t_cub3d;

typedef struct s_player
{
    float   x;
    float   y;
    float   width;
    float   height;
    int     vertical_walk; // -1 for back, +1 for front
    float   rotation_angle;
    int     turn_direction; // -1 for left, +1 for right
    int     horizontal_walk; // -1 for left, +1 for right
    float   walk_speed;
    float   turn_speed;
}   t_player;

void    player_input(t_cub3d *cub3d);
void    player_setup(t_player *player);
void    player_direction(t_player *player);
int     key_up(int keycode,t_cub3d *cub3d);
int     key_down(int keycode, t_cub3d *cub3d);

#endif