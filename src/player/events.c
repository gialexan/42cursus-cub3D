/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 12:35:46 by gialexan          #+#    #+#             */
/*   Updated: 2023/08/05 10:58:53 by gialexan         ###   ########.fr       */
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
    return (0);
}

int mouse_move(int x, int y, t_cub3d *cub3d)
{
	(void)y;
    cub3d->player.mouse_x = cub3d->player.mouse_x - cub3d->window.widht / 2 + x;
    mlx_mouse_move(cub3d->window.mlx_ptr, cub3d->window.mlx_win, cub3d->window.widht / 2, cub3d->window.height / 2);
	return (0);
}
