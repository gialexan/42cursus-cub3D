/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 12:53:30 by gialexan          #+#    #+#             */
/*   Updated: 2023/08/09 12:49:05 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		update_mouse_rotation(t_player *player);
static void		update_player_rotation(t_player *player);
static void		update_player_step(t_player *player, float angle_offset);
static t_bool	check_wall_distance(float player_x, float player_y,
					float cos_angle, float sin_angle);

void	update_player(t_cub3d *cub3d)
{
	if (cub3d->player.mouse_x)
		update_mouse_rotation(&cub3d->player);
	else if (cub3d->player.turn_direction)
		update_player_rotation(&cub3d->player);
	else if (cub3d->player.vertical_walk)
		update_player_step(&cub3d->player, 0);
	else if (cub3d->player.horizontal_walk)
		update_player_step(&cub3d->player, HALF_PI);
}

static void	update_mouse_rotation(t_player *player)
{
	int	move_x;

	move_x = player->mouse_x;
	if (move_x > 0)
		player->rotation_angle += 0.75 * player->turn_speed;
	else if (move_x < 0)
		player->rotation_angle -= 0.75 * player->turn_speed;
	player->mouse_x = 0;
}

static void	update_player_rotation(t_player *player)
{
	player->rotation_angle += player->turn_direction * player->turn_speed;
}

static void	update_player_step(t_player *player, float angle_offset)
{
	float	offset_x;
	float	offset_y;
	float	move_step;
	float	cos_angle;
	float	sin_angle;

	if (player->vertical_walk)
		move_step = player->vertical_walk * player->walk_speed;
	else
		move_step = player->horizontal_walk * player->walk_speed;
	cos_angle = cos(player->rotation_angle + angle_offset);
	sin_angle = sin(player->rotation_angle + angle_offset);
	offset_x = cos_angle * move_step;
	offset_y = sin_angle * move_step;
	if (check_wall_distance(player->x, player->y, cos_angle, sin_angle))
	{
		player->x += offset_x;
		player->y += offset_y;
	}
}

static t_bool	check_wall_distance(float player_x, float player_y,
	float cos_angle, float sin_angle)
{
	float	projected_x;
	float	projected_y;

	projected_x = player_x + (cos_angle * WALL_DISTANCE);
	projected_y = player_y + (sin_angle * WALL_DISTANCE);
	return (!map_has_wall_at(projected_x, projected_y));
}
