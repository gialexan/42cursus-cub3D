/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 18:55:29 by gialexan          #+#    #+#             */
/*   Updated: 2023/07/18 17:44:44 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
 * 1 byte = 8 bits
 * 1 pixel = 32 bits
 * 32 bits / 8 = 4 bytes.
 * 4 bytes por pixel.
*/

// # define WINDOW_WIDTH 600 //colunas
// # define WINDOW_HEIGHT 300 //linhas

# define PI 3.14159265
# define TWO_PI 6.28318530
# define HALF_PI (PI / 2)

# define FOV_ANGLE (60 * (PI / 180))

# define FPS 30
# define FRAME_TIME_LENGTH (1000 / FPS)

# define RED_PIXEL 0xFF0000
# define GREEN_PIXEL 0xFF00
# define WHITE_PIXEL 0xFFFFFF
# define BLACK_PIXEL 0x000000
# define BLUE_PIXEL 0xff0
# define YELLOW_PIXEL 0xffff32

# define TILE_SIZE 64
# define MAP_NUM_ROWS 13
# define MAP_NUM_COLS 20

# define WINDOW_WIDTH (MAP_NUM_COLS * TILE_SIZE)
# define WINDOW_HEIGHT (MAP_NUM_ROWS * TILE_SIZE)

# define MINIMAP_SCALE_FACTOR 0.3
# define NUM_RAYS WINDOW_WIDTH


void    render_map(t_cub3d *cub3d)
{
    int x;
    int y;
    int tile_x;
    int tile_y;
    int tile_color;

    const int map[MAP_NUM_ROWS][MAP_NUM_COLS] = {
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

    y = -1;
    while (++y < MAP_NUM_ROWS)
    {
        x = -1;
        while (++x < MAP_NUM_COLS)
        {
            tile_x = (x * TILE_SIZE);
            tile_y = (y * TILE_SIZE);
            tile_color = map[y][x] != 0 ? WHITE_PIXEL : BLACK_PIXEL;
            draw_rect(&cub3d->img, (t_rect){tile_x, tile_y, TILE_SIZE, TILE_SIZE , tile_color});


            /* Minimap
            tile_x = (x * TILE_SIZE) * MINIMAP_SCALE_FACTOR;
            tile_y = (y * TILE_SIZE) * MINIMAP_SCALE_FACTOR;
            tile_color = map[x][y] != 0 ? RED_PIXEL : GREEN_PIXEL;
            draw_rect(&mlx->img, (t_rect){tile_y, tile_x, TILE_SIZE * MINIMAP_SCALE_FACTOR, TILE_SIZE * MINIMAP_SCALE_FACTOR, tile_color});
            */
        }
    }
}

void    render_player(t_cub3d *cub3d)
{                                    
    draw_rect(&cub3d->img, (t_rect){cub3d->ppl.x, 
                                    cub3d->ppl.y, 
                                    cub3d->ppl.width, 
                                    cub3d->ppl.height, 
                                    RED_PIXEL});
    draw_line(&cub3d->img, (t_line){cub3d->ppl.x, 
                                    cub3d->ppl.y, 
                                    cub3d->ppl.x + (cos(cub3d->ppl.rotation_angle) * 40), 
                                    cub3d->ppl.y + (sin(cub3d->ppl.rotation_angle) * 40), 
                                    BLACK_PIXEL});
}

void    render_rays(t_cub3d *cub3d)
{
    int i;

    i = 0;
    while (i < NUM_RAYS)
    {
        draw_line(&cub3d->img, (t_line){cub3d->ppl.x, 
                                        cub3d->ppl.y, 
                                        cub3d->rays[i].wall_hit_x, 
                                        cub3d->rays[i].wall_hit_y, 
                                        RED_PIXEL});
        i += 20;
    }
}

int	render(t_cub3d *cub3d)
{
    //Renderiza o mapa
    render_map(cub3d);

    //Lança os raios
    cast_rays(cub3d);
    render_rays(cub3d);

    //Renderiza player
    render_player(cub3d);

    //Puxa imagem para tela.
    mlx_put_image_to_window(cub3d->win.mlx_ptr, cub3d->win.mlx_win, cub3d->img.mlx_img, 0, 0);
    return (0);
}

void    create_window(t_cub3d *cub3d)
{
    cub3d->win.mlx_ptr = mlx_init();
	cub3d->win.mlx_win = mlx_new_window(cub3d->win.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "cub3D");
}

void    create_image(t_cub3d *cub3d)
{
    cub3d->img.mlx_img = mlx_new_image(cub3d->win.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	cub3d->img.addr = mlx_get_data_addr(cub3d->img.mlx_img, &cub3d->img.bpp, &cub3d->img.line_len, &cub3d->img.endian);
}

void    player_input(t_cub3d *cub3d)
{
    mlx_hook(cub3d->win.mlx_win, KEY_PRESS, KEY_PRESS_MASK, &key_down, &cub3d);
    mlx_hook(cub3d->win.mlx_win, KEY_RELEASE, KEY_RELEASE_MASK, &key_up, &cub3d);
}

int main(void)
{
	t_cub3d cub3d;

	//cria janela
    create_window(&cub3d);

	//cria imagem
    create_image(&cub3d);

    //inicializa setup jogador
    player_setup(&cub3d);

    //Renderiza o jogo
    render(&cub3d);
    
    //Entrada do teclado.
    player_input(&cub3d);

	mlx_loop(cub3d.win.mlx_ptr);
	return (0);
}
