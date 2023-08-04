/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 12:28:05 by gialexan          #+#    #+#             */
/*   Updated: 2023/08/04 12:53:00 by gialexan         ###   ########.fr       */
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
    cub3d->player.walk_speed = 5;
    cub3d->player.turn_speed = 5 * (PI / 180);
}

void    update_mouse_rotation(t_cub3d *cub3d)
{
    int	move_x;

	move_x = cub3d->mouse.x;
	cub3d->mouse.x = 0;
	cub3d->mouse.y = 0;
    if (move_x > 0)
		cub3d->player.rotation_angle += 1.0 * (2 * (PI / 180));
    else if (move_x < 0)
	 	cub3d->player.rotation_angle -= 1.0 * (2 * (PI / 180));
    
}

int mouse_move(int x, int y, t_cub3d *cub3d)
{
    (void) x;
	(void) y;
    cub3d->mouse.x = cub3d->mouse.x - cub3d->window.widht / 2 + x; 
    cub3d->mouse.y = cub3d->mouse.y - cub3d->window.height / 2 + y; 
    mlx_mouse_move(cub3d->window.mlx_ptr, cub3d->window.mlx_win, cub3d->window.widht / 2, cub3d->window.height / 2);
	return (0);
}

void    player_input(t_cub3d *cub3d)
{
    mlx_hook(cub3d->window.mlx_win, KEY_PRESS, KEY_PRESS_MASK, &key_down, cub3d);
    mlx_hook(cub3d->window.mlx_win, KEY_RELEASE, KEY_RELEASE_MASK, &key_up, cub3d);
    mlx_hook(cub3d->window.mlx_win, 06, 1L << 6, mouse_move, cub3d);
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
