/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 18:55:29 by gialexan          #+#    #+#             */
/*   Updated: 2023/07/20 10:30:38 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int map[MAP_NUM_ROWS][MAP_NUM_COLS] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 ,1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

int map_has_wall_at(float x, float y)
{
    int map_index_x;
    int map_index_y;

    if ((x < 0 || x > WINDOW_WIDTH) || (y < 0 || y > WINDOW_HEIGHT))
        return TRUE;
    map_index_x = floor(x / TILE_SIZE);
    map_index_y = floor(y / TILE_SIZE);
    return (map[map_index_y][map_index_x] != 0);
}

int main(void)
{
	printf("cub3D!\n");

    t_cub3d cub3d;
    
    cub3d.map = malloc(MAP_NUM_ROWS * sizeof(int **));
    for (int i = 0; i < MAP_NUM_ROWS; i++) {
        cub3d.map[i] = (int *)malloc(MAP_NUM_COLS * sizeof(int));
        for (int j = 0; j < MAP_NUM_COLS; j++) {
            cub3d.map[i][j] = map[i][j];
        }
    }

	//Window.
    init_window(&cub3d.window);

	//Image.
    create_image(&cub3d.window, &cub3d.image);

    //Player Setup.
    player_setup(&cub3d.player);

    //Render.
    render_game(&cub3d);

    //Input.
    player_input(&cub3d);

	//Hook.
	//mlx_loop_hook(mlx.mlx_ptr, &render, &mlx);

    //Loop.
	mlx_loop(cub3d.window.mlx_ptr);
	return (0);
}
