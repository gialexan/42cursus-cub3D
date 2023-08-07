/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 12:53:30 by gialexan          #+#    #+#             */
/*   Updated: 2023/08/07 09:40:13 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void    update_mouse_rotation(t_player *player);
static void    update_player_rotation(t_player *player);
static void    update_player_direction(t_player *player, float angle_offset);

void    update_player(t_cub3d *cub3d)
{
    if (cub3d->player.mouse_x)
        update_mouse_rotation(&cub3d->player);
    else if (cub3d->player.turn_direction)
        update_player_rotation(&cub3d->player);
    else if (cub3d->player.vertical_walk)
        update_player_direction(&cub3d->player, 0);
    else if (cub3d->player.horizontal_walk)
        update_player_direction(&cub3d->player, HALF_PI);
}

static void    update_mouse_rotation(t_player *player)
{
    int	move_x;

	move_x = player->mouse_x;
    if (move_x > 0)
		player->rotation_angle += 0.5 * player->turn_speed;
    else if (move_x < 0)
	 	player->rotation_angle -= 0.5 * player->turn_speed;
	player->mouse_x = 0;
}

static void    update_player_rotation(t_player *player)
{
    player->rotation_angle += player->turn_direction * player->turn_speed;
}

static void    update_player_direction(t_player *player, float angle_offset)
{
    float new_ppl_x;
    float new_ppl_y;
    float hypotenuse;

    if (player->vertical_walk)
        hypotenuse = player->vertical_walk * player->walk_speed;
    else
        hypotenuse = player->horizontal_walk * player->walk_speed;
    new_ppl_x = player->x + (cos(player->rotation_angle + angle_offset) * hypotenuse);
    new_ppl_y = player->y + (sin(player->rotation_angle + angle_offset) * hypotenuse);
    if (!map_has_wall_at(new_ppl_x, new_ppl_y))
    {
        player->x = new_ppl_x;
        player->y = new_ppl_y;
    }
}
