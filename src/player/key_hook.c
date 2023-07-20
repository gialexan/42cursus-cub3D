/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 12:35:46 by gialexan          #+#    #+#             */
/*   Updated: 2023/07/20 10:24:46 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int key_up(int keycode, t_cub3d *cub3d)
{
    if (keycode == KEY_W)
        cub3d->player.vertical_walk = 0;
    else if (keycode == KEY_S)
        cub3d->player.vertical_walk = 0;
    else if (keycode == KEY_D)
        cub3d->player.horizontal_walk = 0;
    else if (keycode == KEY_A)
        cub3d->player.horizontal_walk = 0;
    else if (keycode == KEY_LEFT_ARROW)
        cub3d->player.turn_direction = 0;
    else if (keycode == KEY_RIGHT_ARROW)
        cub3d->player.turn_direction = 0;
    return (0);
}

int key_down(int keycode, t_cub3d *cub3d)
{
    if (keycode == KEY_W)
        cub3d->player.vertical_walk += 1;
    else if (keycode == KEY_S)
        cub3d->player.vertical_walk -= 1;
    else if (keycode == KEY_D)
        cub3d->player.horizontal_walk += 1;
    else if (keycode == KEY_A)
        cub3d->player.horizontal_walk -= 1;
    else if (keycode == KEY_RIGHT_ARROW)
        cub3d->player.turn_direction += 1;
    else if (keycode == KEY_LEFT_ARROW)
        cub3d->player.turn_direction -= 1;
    //ray_direction(ppl);
    player_direction(&cub3d->player);
    render_game(cub3d);
    return (0);
}
