/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 12:53:30 by gialexan          #+#    #+#             */
/*   Updated: 2023/07/20 10:24:42 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    player_direction(t_player *player)
{
    float new_ppl_x;
    float new_ppl_y;
    float hypotenuse;

    if (player->turn_direction)
    {
        //controle da seta
        //Pega angulo de rotação, no ínicio é PI/2 que dá direção central.
        player->rotation_angle += player->turn_direction * player->turn_speed;
    }
    else if (player->horizontal_walk)
    {
        hypotenuse = player->horizontal_walk * player->walk_speed;
        new_ppl_x = player->x + (cos(player->rotation_angle + HALF_PI) * hypotenuse);
        new_ppl_y = player->y + (sin(player->rotation_angle + HALF_PI) * hypotenuse);
    }
    else if (player->vertical_walk)
    {
        hypotenuse = player->vertical_walk * player->walk_speed;
        new_ppl_x = player->x + (cos(player->rotation_angle) * hypotenuse);
        new_ppl_y = player->y + (sin(player->rotation_angle) * hypotenuse);
    }
    if (!map_has_wall_at(new_ppl_x, new_ppl_y))
    {
        player->x = new_ppl_x;
        player->y = new_ppl_y;
    }
}
