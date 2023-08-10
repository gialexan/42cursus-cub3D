/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 18:55:29 by gialexan          #+#    #+#             */
/*   Updated: 2023/08/10 17:41:07 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void     game_loop(t_cub3d *cub3d);
int      exit_game(t_cub3d *cub3d);

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

// TODO: Lê o mapa e armazenar no ponteiro: cub3d->map.map
void    load_map(t_cub3d *cub3d, char *path)
{
    int fd;

    fd = open(path, O_RDONLY);
    if (fd == -1)
    {
        if ((ft_strncmp(((path + ft_strlen(path)) - 4), ".cub", 5))
            || (ft_strlen(((path + ft_strlen(path)) - 5)) < 5))
            cub3d_error(cub3d, MAP_EXTENSION_ERROR, MAP_EXTENSION_MSG);
        else
            cub3d_error(cub3d, MAP_PATH_OR_PERM_ERROR, MAP_PATH_OR_PERM_MSG);
    }
    //cub3d->map.map = generate_map(path);
}

int	main(int argc, char **argv)
{
	t_cub3d	cub3d;

    if (argc != 2)
        cub3d_error(&cub3d, INVALID_ARGS_ERROR, INVALID_ARGS_MSG);
    load_map(&cub3d, argv[1]);
    exit(1);
    
    // TODO: Verificar se informações do mapa são válidos: TEXTURAS, CORES, MAPA
    // check_map();
    

    //char **map_dup = generate_map("./dust.cub");
    //pegar a maior linha;
    //normalizar o mapa para todas linhas ser igual lenght da maior linha ou seja trocar espaços por 2

    // t_bool result = TRUE;
    
    // TODO: VERIFICAR SE O MAPA POSSUI CARACTER INVÁLIDOS QUE NÃO SEJA W,N,E,O,1,0
    //flood_fill(map_dup, 1, 3);
    // TODO: VARRER O MAPA MODIFICADO PELA FLOOD_FILL E PROCURAR CARACTER QUE SEJAM DIFERENTES DE 6,5,1


    // for (int i = 0; map_dup[i]; i++)
    // {
    //     for (int j = 0; map_dup[i][j]; j++)
    //     {
    //         if (map_dup[i][j] == '@')
    //             printf("%s%c%s", "\033[32m", map_dup[i][j], "\x1b[0;30m");
    //         else if (map_dup[i][j] == '!')
    //             printf("%s%c%s", "\033[31m", map_dup[i][j], "\x1b[0;30m");
    //         else
    //             printf("%s%c%s", "\033[31m", map_dup[i][j], "\x1b[0;30m");
    //     }
    //     printf("\n");
    // }


    // Player course.
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

    // Texture ptr.
    cub3d.textures[WEST].img_ptr = NULL;
    cub3d.textures[EAST].img_ptr = NULL;
    cub3d.textures[NORTH].img_ptr = NULL;
    cub3d.textures[SOUTH].img_ptr = NULL;
    cub3d.color_buffer = NULL;

    cub3d.map.map = malloc(MAP_NUM_ROWS * sizeof(int **));
    for (int i = 0; i < MAP_NUM_ROWS; i++)
    {
        cub3d.map.map[i] = malloc(MAP_NUM_COLS * sizeof(int));
        for (int j = 0; j < MAP_NUM_COLS; j++)
            cub3d.map.map[i][j] = map[i][j];
    }

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
        free(cub3d->map.map[i]);
    free(cub3d->map.map);
    destroy_texture(&cub3d->window, cub3d->textures);
    destroy_image(&cub3d->window, &cub3d->image);
    destroy_window(&cub3d->window);
    exit(1);
    return (1);
}