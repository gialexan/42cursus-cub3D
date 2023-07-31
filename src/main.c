/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 18:55:29 by gialexan          #+#    #+#             */
/*   Updated: 2023/07/31 17:33:22 by gialexan         ###   ########.fr       */
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

void    load_texture(void)
{
    //TODO: Vai carregar as texturas do mapa.
    //Se textura for maior 64x64 retorna erro.
    //Se textura for inválida retorna erro.
}

int main(void)
{
	printf("cub3D!\n");

    t_cub3d cub3d;

    cub3d.textures[0] = (int *) REDBRICK_TEXTURE;
    cub3d.textures[1] = (int *) PURPLESTONE_TEXTURE;
    cub3d.textures[2] = (int *) MOSSYSTONE_TEXTURE;
    cub3d.textures[3] = (int *) GRAYSTONE_TEXTURE;
    cub3d.textures[4] = (int *) COLORSTONE_TEXTURE;
    cub3d.textures[5] = (int *) BLUESTONE_TEXTURE;
    cub3d.textures[6] = (int *) WOOD_TEXTURE;
    cub3d.textures[7] = (int *) EAGLE_TEXTURE;

    cub3d.color_buffer = NULL;

    cub3d.map = malloc(MAP_NUM_ROWS * sizeof(int **));
    for (int i = 0; i < MAP_NUM_ROWS; i++)
    {
        cub3d.map[i] = (int *)malloc(MAP_NUM_COLS * sizeof(int));
        for (int j = 0; j < MAP_NUM_COLS; j++)
            cub3d.map[i][j] = map[i][j];
    }

    //load_texture()

	//Window.
    init_window(&cub3d.window);


    // t_image teste1;
    // t_image teste2;
    // t_image teste3;
    // t_image teste4;

    // teste1.mlx_img = mlx_xpm_file_to_image(cub3d.window.mlx_ptr, "./src/brick_blue.xpm", &teste1.width, &teste1.height);
    // teste2.mlx_img = mlx_xpm_file_to_image(cub3d.window.mlx_ptr, "./src/brick_green.xpm", &teste2.width, &teste2.height);
    // teste3.mlx_img = mlx_xpm_file_to_image(cub3d.window.mlx_ptr, "./src/brick_purple.xpm", &teste3.width, &teste3.height);
    // teste4.mlx_img = mlx_xpm_file_to_image(cub3d.window.mlx_ptr, "./src/brick_yellow.xpm", &teste4.width, &teste4.height);

    // teste1.addr = mlx_get_data_addr(teste1.mlx_img, &teste1.bpp, &teste1.line_len, &teste1.endian);
    // teste2.addr = mlx_get_data_addr(teste2.mlx_img, &teste2.bpp, &teste2.line_len, &teste2.endian);
    // teste3.addr = mlx_get_data_addr(teste3.mlx_img, &teste3.bpp, &teste3.line_len, &teste3.endian);
    // teste4.addr = mlx_get_data_addr(teste4.mlx_img, &teste4.bpp, &teste4.line_len, &teste4.endian);

    // cub3d.textures[0] = (int *) teste1.addr;
    // cub3d.textures[1] = (int *) teste2.addr;
    // cub3d.textures[2] = (int *) teste3.addr;
    // cub3d.textures[3] = (int *) teste4.addr;
    // cub3d.textures[4] = (int *) COLORSTONE_TEXTURE;
    // cub3d.textures[5] = (int *) BLUESTONE_TEXTURE;
    // cub3d.textures[6] = (int *) WOOD_TEXTURE;
    // cub3d.textures[7] = (int *) EAGLE_TEXTURE;

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
