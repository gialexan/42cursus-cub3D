/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 18:55:29 by gialexan          #+#    #+#             */
/*   Updated: 2023/08/01 15:20:26 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "../include/imagens_teste.h"

const int map[MAP_NUM_ROWS][MAP_NUM_COLS] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 ,1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
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


// TEMOS A ESTRUTURA COLOR
// int ceil_r
// int ceil_g
// int ceil_b
// int floor_r
// int floor_g
// int floor_b


// TEMOS ESTRUTURA MAPA:
// char **map;
// char *norte;
// char *sul;
// char *leste;
// char *oeste;
// variável para estrutura colocar;


/*
    // cub3d.textures[0] = (int *) REDBRICK_TEXTURE;
    // cub3d.textures[1] = (int *) PURPLESTONE_TEXTURE;
    // cub3d.textures[2] = (int *) MOSSYSTONE_TEXTURE;
    // cub3d.textures[3] = (int *) GRAYSTONE_TEXTURE;
    // cub3d.textures[4] = (int *) COLORSTONE_TEXTURE;
    // cub3d.textures[5] = (int *) BLUESTONE_TEXTURE;
    // cub3d.textures[6] = (int *) WOOD_TEXTURE;
    // cub3d.textures[7] = (int *) EAGLE_TEXTURE;
*/

int main(void)
{
	printf("cub3D!\n");

    t_cub3d cub3d;

    cub3d.map_teste.ea_path = "./src/brick_blue.xpm";
    cub3d.map_teste.no_path = "./src/brick_green.xpm";
    cub3d.map_teste.so_path = "./src/brick_purple.xpm";
    cub3d.map_teste.we_path = "./src/brick_yellow.xpm";

    cub3d.color_buffer = NULL;

    cub3d.map = malloc(MAP_NUM_ROWS * sizeof(int **));
    for (int i = 0; i < MAP_NUM_ROWS; i++)
    {
        cub3d.map[i] = (int *)malloc(MAP_NUM_COLS * sizeof(int));
        for (int j = 0; j < MAP_NUM_COLS; j++)
            cub3d.map[i][j] = map[i][j];
    }

    // check_map()

	//Window.
    init_window(&cub3d.window);

    //Sprites
    load_texture(&cub3d);

	//Image.
    create_image(&cub3d.window, &cub3d.image);

    //Player Setup.
    player_setup(&cub3d.player);

    //Render.
    render_game(&cub3d);

    //Input.
    player_input(&cub3d);

    //Loop.
	mlx_loop(cub3d.window.mlx_ptr);
	return (0);
}
