/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 18:55:29 by gialexan          #+#    #+#             */
/*   Updated: 2023/08/05 10:47:21 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// const int map[MAP_NUM_ROWS][MAP_NUM_COLS] = {
//     {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
//     {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
//     {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
//     {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
//     {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
//     {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
//     {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
//     {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
//     {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
//     {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
// };

const int map[MAP_NUM_ROWS][MAP_NUM_COLS] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1},
    {1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1},
    {1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

t_bool map_has_wall_at(float x, float y)
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
    t_cub3d cub3d;

    // Player course
    cub3d.map.player_course = NORTH;

    // Flooor color.
    cub3d.map.color.floor_r = 0;
    cub3d.map.color.floor_g = 0;
    cub3d.map.color.floor_b = 0;

    // Ceil color.
    cub3d.map.color.ceil_r = 0;
    cub3d.map.color.ceil_g = 0;
    cub3d.map.color.ceil_b = 0;

    // Texture path.
    cub3d.map.ea_path = "./assets/textures/brick_blue.xpm";
    cub3d.map.no_path = "./assets/textures/brick_green.xpm";
    cub3d.map.so_path = "./assets/textures/brick_purple.xpm";
    cub3d.map.we_path = "./assets/textures/brick_yellow.xpm";

    cub3d.color_buffer = NULL;
    cub3d.map.map = malloc(MAP_NUM_ROWS * sizeof(int **));
    for (int i = 0; i < MAP_NUM_ROWS; i++)
    {
        cub3d.map.map[i] = (int *)malloc(MAP_NUM_COLS * sizeof(int));
        for (int j = 0; j < MAP_NUM_COLS; j++)
            cub3d.map.map[i][j] = map[i][j];
    }


    init_window(&cub3d);
    load_texture(&cub3d);
    create_image(&cub3d);
    player_setup(&cub3d);
    player_input(&cub3d);
    mlx_loop_hook(cub3d.window.mlx_ptr, render_game, &cub3d);
	mlx_loop(cub3d.window.mlx_ptr);
	return (0);
}
