/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 12:28:05 by gialexan          #+#    #+#             */
/*   Updated: 2023/08/02 19:49:33 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int   exit_game(t_cub3d *cub3d);
static float get_player_course(t_cub3d *cub3d);

void    player_setup(t_cub3d *cub3d)
{
    cub3d->player.x = WINDOW_WIDTH / 2;
    cub3d->player.y = WINDOW_HEIGHT / 2;
    cub3d->player.width = 5;
    cub3d->player.height = 5;
    cub3d->player.turn_direction = 0;
    cub3d->player.vertical_walk = 0;
    cub3d->player.horizontal_walk = 0;
    cub3d->player.rotation_angle = get_player_course(cub3d);
    cub3d->player.walk_speed = 15;
    cub3d->player.turn_speed = 15 * (PI / 180);
}

void    player_input(t_cub3d *cub3d)
{
    mlx_hook(cub3d->window.mlx_win, KEY_PRESS, KEY_PRESS_MASK, &key_down, cub3d);
    mlx_hook(cub3d->window.mlx_win, KEY_RELEASE, KEY_RELEASE_MASK, &key_up, cub3d);
    mlx_hook(cub3d->window.mlx_win, DESTROY_NOTIFY, NO_EVENT_MASK, &exit_game, cub3d);
}

static  float get_player_course(t_cub3d *cub3d)
{
    t_compass course;

    course = cub3d->map.player_course;
    if (course == SOUTH)
        return (ANGLE_SOUTH);
    if (course == NORTH)
        return (ANGLE_NORTH);
    if (course == WEST)
        return (ANGLE_WEST);
    if (course == EAST)
        return (ANGLE_EAST);
    return (0);
}

static int   exit_game(t_cub3d *cub3d)
{
    int i;

    i = -1;
    free(cub3d->color_buffer);
    while (++i < MAP_NUM_ROWS)
        free(cub3d->map.map[i]);
    free(cub3d->map.map);
    destroy_texture(&cub3d->window, cub3d->textures);
    destroy_image(&cub3d->window, &cub3d->image);
    destroy_window(&cub3d->window);
    destroy_display(&cub3d->window);
    exit(1);
    return (1);
}
