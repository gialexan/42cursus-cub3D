/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 12:53:30 by gialexan          #+#    #+#             */
/*   Updated: 2023/07/26 17:34:19 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void    update_player_rotation(t_player *player);
static void    update_player_direction(t_player *player, int walk_direction, float angle_offset);

void    update_player(t_player *player)
{
    if (player->turn_direction)
        update_player_rotation(player);
    else if (player->vertical_walk)
        update_player_direction(player, player->vertical_walk, 0);
    else if (player->horizontal_walk)
        update_player_direction(player, player->horizontal_walk, HALF_PI);
}

static void    update_player_rotation(t_player *player)
{
    player->rotation_angle += player->turn_direction * player->turn_speed;
}

static void    update_player_direction(t_player *player, int walk_direction, float angle_offset)
{
    float new_ppl_x;
    float new_ppl_y;
    float hypotenuse;

    hypotenuse = walk_direction * player->walk_speed;
    new_ppl_x = player->x + (cos(player->rotation_angle + angle_offset) * hypotenuse);
    new_ppl_y = player->y + (sin(player->rotation_angle + angle_offset) * hypotenuse);
    if (!map_has_wall_at(new_ppl_x, new_ppl_y))
    {
        player->x = new_ppl_x;
        player->y = new_ppl_y;
    }
}
