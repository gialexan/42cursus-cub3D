/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 15:06:29 by gialexan          #+#    #+#             */
/*   Updated: 2023/07/18 18:31:22 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void player_setup(t_cub3d *cub3d)
{
    cub3d->ppl.x = WINDOW_WIDTH / 2;
    cub3d->ppl.y = WINDOW_HEIGHT / 2;
    cub3d->ppl.width = 5;
    cub3d->ppl.height = 5;
    cub3d->ppl.turn_direction = 0;
    cub3d->ppl.vertical_walk = 0;
    cub3d->ppl.horizontal_walk = 0;
    cub3d->ppl.rotation_angle = (PI / 2);
    cub3d->ppl.walk_speed = 10;
    cub3d->ppl.turn_speed = 1 * (PI / 180);
}

void    player_input(t_cub3d *cub3d)
{
    mlx_hook(cub3d->win.mlx_win, KEY_PRESS, KEY_PRESS_MASK, &key_down, &cub3d);
    mlx_hook(cub3d->win.mlx_win, KEY_RELEASE, KEY_RELEASE_MASK, &key_up, &cub3d);
}
