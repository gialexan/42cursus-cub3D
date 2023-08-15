/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 18:55:29 by gialexan          #+#    #+#             */
/*   Updated: 2023/08/15 19:19:42 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void     game_loop(t_cub3d *cub3d);

int	main(int argc, char **argv)
{
	t_cub3d	cub3d;

	if (argc != 2)
		cub3d_error(NULL, INVALID_ARGS_ERROR, INVALID_ARGS_MSG);
	init_cub3d(&cub3d);
	open_cubfile(&cub3d, argv[1]);
	parser_cubfile(&cub3d);
	init_window(&cub3d);
	create_image(&cub3d);
	load_texture(&cub3d);
	player_setup(&cub3d);
	game_loop(&cub3d);
	return (0);
}

static void    game_loop(t_cub3d *cub3d)
{
	cub3d->color_buffer = malloc((WINDOW_WIDTH * WINDOW_HEIGHT) * sizeof(int));
	if (!cub3d->color_buffer)
		cub3d_error(cub3d, COLOR_BUFFER_MALLOC_ERROR, COLOR_BUFFER_MSG);
	mlx_hook(cub3d->window.mlx_win, KeyPress, KeyPressMask, &key_down, cub3d);
	mlx_hook(cub3d->window.mlx_win, KeyRelease, KeyReleaseMask, &key_up, cub3d);
	mlx_hook(cub3d->window.mlx_win, MotionNotify, PointerMotionMask, &mouse_move, cub3d);
	mlx_hook(cub3d->window.mlx_win, DestroyNotify, NoEventMask, &exit_game, cub3d);
	mlx_loop_hook(cub3d->window.mlx_ptr, render_game, cub3d);
	mlx_loop(cub3d->window.mlx_ptr);
}

int   exit_game(t_cub3d *cub3d)
{
	int i;

	i = -1;
	free(cub3d->color_buffer);
	while (++i < MAP_NUM_ROWS)
		free(cub3d->map[i]);
	free(cub3d->map);
	destroy_texture(&cub3d->window, cub3d->textures);
	destroy_image(&cub3d->window, &cub3d->image);
	destroy_window(&cub3d->window);
	exit(1);
	return (1);
}