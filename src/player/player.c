/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 12:28:05 by gialexan          #+#    #+#             */
/*   Updated: 2023/08/01 18:03:30 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int   exit_game(t_cub3d *cub3d);

void    player_setup(t_player *player)
{
    player->x = WINDOW_WIDTH / 2;
    player->y = WINDOW_HEIGHT / 2;
    player->width = 5;
    player->height = 5;
    player->turn_direction = 0;
    player->vertical_walk = 0;
    player->horizontal_walk = 0;
    player->rotation_angle = (PI / 2) + 3;
    player->walk_speed = 15;
    player->turn_speed = 15 * (PI / 180);
}

void    player_input(t_cub3d *cub3d)
{
    mlx_hook(cub3d->window.mlx_win, KEY_PRESS, KEY_PRESS_MASK, &key_down, cub3d);
    mlx_hook(cub3d->window.mlx_win, KEY_RELEASE, KEY_RELEASE_MASK, &key_up, cub3d);
    mlx_hook(cub3d->window.mlx_win, DESTROY_NOTIFY, NO_EVENT_MASK, &exit_game, cub3d);
}

static int   exit_game(t_cub3d *cub3d)
{
    int i;

    i = -1;
    free(cub3d->color_buffer);
    while (++i < MAP_NUM_ROWS)
        free(cub3d->map.map[i]);
    free(cub3d->map.map);
    destroy_image(&cub3d->window, &cub3d->image);
    destroy_window(&cub3d->window);
    destroy_display(&cub3d->window);
    exit(1);
    return (1);
}
