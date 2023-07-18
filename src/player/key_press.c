/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 15:03:47 by gialexan          #+#    #+#             */
/*   Updated: 2023/07/18 18:17:18 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int key_up(int keycode, t_cub3d *cub3d)
{
    if (keycode == KEY_W)
        cub3d->ppl.vertical_walk = 0;
    else if (keycode == KEY_S)
        cub3d->ppl.vertical_walk = 0;
    else if (keycode == KEY_D)
        cub3d->ppl.horizontal_walk = 0;
    else if (keycode == KEY_A)
        cub3d->ppl.horizontal_walk = 0;
    else if (keycode == KEY_LEFT_ARROW)
        cub3d->ppl.turn_direction = 0;
    else if (keycode == KEY_RIGHT_ARROW)
        cub3d->ppl.turn_direction = 0;
    return (0);
}

int key_down(int keycode, t_cub3d *cub3d)
{
    if (keycode == KEY_W)
        cub3d->ppl.vertical_walk += 1;
    else if (keycode == KEY_S)
        cub3d->ppl.vertical_walk -= 1;
    else if (keycode == KEY_D)
        cub3d->ppl.horizontal_walk += 1;
    else if (keycode == KEY_A)
        cub3d->ppl.horizontal_walk -= 1;
    else if (keycode == KEY_RIGHT_ARROW)
        cub3d->ppl.turn_direction += 1;
    else if (keycode == KEY_LEFT_ARROW)
        cub3d->ppl.turn_direction -= 1;
    player_direction(cub3d);
    render(cub3d);
    return (0);
}
