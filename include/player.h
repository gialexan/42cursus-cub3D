/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 12:28:12 by gialexan          #+#    #+#             */
/*   Updated: 2023/08/15 19:05:36 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

typedef struct s_cub3d	t_cub3d;

typedef struct s_player
{
	float	x;
	float	y;
	float	width;
	float	height;
	int		vertical_walk;
	float	rotation_angle;
	int		turn_direction;
	int		horizontal_walk;
	float	walk_speed;
	float	turn_speed;
	int		mouse_x;
	char	course;
}	t_player;

/***************************************************************************\
 * PLAYER/PLAYER.C
\***************************************************************************/

void	player_setup(t_cub3d *cub3d);

/***************************************************************************\
 * PLAYER/UPDATE.C
\***************************************************************************/

void	update_player(t_cub3d *cub3d);

/***************************************************************************\
 * PLAYER/EVENT.C
\***************************************************************************/

int		key_up(int keycode, t_cub3d *cub3d);
int		key_down(int keycode, t_cub3d *cub3d);
int		mouse_move(int x, int y, t_cub3d *cub3d);

#endif