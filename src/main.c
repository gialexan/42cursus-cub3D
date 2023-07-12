/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 18:55:29 by gialexan          #+#    #+#             */
/*   Updated: 2023/07/12 12:31:22 by gialexan         ###   ########.fr       */
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

# define NUM_RAYS WINDOW_WIDTH

# define FPS 30
# define FRAME_TIME_LENGTH (1000 / FPS)

# define RED_PIXEL 0xFF0000
# define GREEN_PIXEL 0xFF00
# define WHITE_PIXEL 0xFFFFFF
# define BLACK_PIXEL 0x000000

# define TILE_SIZE 64
# define MAP_NUM_ROWS 13
# define MAP_NUM_COLS 20

# define WINDOW_WIDTH (MAP_NUM_COLS * TILE_SIZE)
# define WINDOW_HEIGHT (MAP_NUM_ROWS * TILE_SIZE)
# define MINIMAP_SCALE_FACTOR 0.3 


typedef struct s_rect
{
    int	x;
    int	y;
    int width;
    int height;
    int color;
}   t_rect;

typedef struct s_img
{
	void	*mlx_img;
    char	*addr;
    int		bpp; /* bits per pixel */
    int		line_len;
    int		endian;
}   t_img;

typedef struct s_player
{
    float x;
    float y;
    float width;
    float height;
    int vertical_walk; // -1 for back, +1 for front
    int turn_direction; // -1 for left, +1 for right
    int horizontal_walk; // -1 for left, +1 for right
    float rotation_angle;
    float walk_speed;
    float turn_speed;
}   t_player;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*mlx_win;
	t_img	img;
    int test;
}	t_mlx;

t_mlx       mlx;
t_player    ppl;

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

/*
 * cada byte é definido manualmente de maneira diferente, dependendo do endianness.
 * Se você não sabe o que é endianidade, recomendo que leia:
 * https://www.freecodecamp.org/news/what-is-endianness-big-endian-vs-little-endian/
 * 
*/
void	img_pix_put(t_img *img, unsigned int x, unsigned int y, int color)
{
    char    *pixel;

    if (x > WINDOW_WIDTH || y > WINDOW_HEIGHT)
        return ;
    pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
    *(int *)pixel = color;
}

void draw_line(int x0, int y0, int x1, int y1, int color) {
    int deltaX = (x1 - x0);
    int deltaY = (y1 - y0);

    int longestSideLength = (abs(deltaX) >= abs(deltaY)) ? abs(deltaX) : abs(deltaY);

    float xIncrement = deltaX / (float)longestSideLength;
    float yIncrement = deltaY / (float)longestSideLength;

    float currentX = x0;
    float currentY = y0;

    for (int i = 0; i < longestSideLength; i++) {
        img_pix_put(&mlx.img, round(currentX), round(currentY), color);
        currentX += xIncrement;
        currentY += yIncrement;
    }
}

void	render_background(t_img *img, int color)
{
    int	i;
    int	j;

    i = 0;
    while (i < WINDOW_HEIGHT)
    {
        j = 0;
        while (j < WINDOW_WIDTH)
            img_pix_put(img, j++, i, color);
        ++i;
    }
}

/*
 * Primeiro parametro ponteiro img da mlx
 * Segundo e terceiro parametro x, y parametro 
 * Terceiro parametro width -> largura
 * Quarto parametro height -> altura
 * Quinto parametro cor
*/
int render_rect(t_img *img, t_rect rect)
{
    int	i;
    int j;

    i = rect.y;
    while (i < rect.y + rect.height)
    {
        j = rect.x;
        while (j < rect.x + rect.width)
            img_pix_put(img, j++, i, rect.color);
        ++i;
    }
    return (0);
}

void    draw_map(t_mlx *mlx)
{
    int x;
    int y;
    int tile_x;
    int tile_y;
    int tile_color;

    y = -1;
    while (++y < MAP_NUM_ROWS)
    {
        x = -1;
        while (++x < MAP_NUM_COLS)
        {
            tile_x = (x * TILE_SIZE);
            tile_y = (y * TILE_SIZE);
            tile_color = map[y][x] != 0 ? RED_PIXEL : GREEN_PIXEL;
            render_rect(&mlx->img, (t_rect){tile_x, tile_y, TILE_SIZE - 1, TILE_SIZE - 1, tile_color});


            /* Minimap
            tile_x = (x * TILE_SIZE) * MINIMAP_SCALE_FACTOR;
            tile_y = (y * TILE_SIZE) * MINIMAP_SCALE_FACTOR;
            tile_color = map[x][y] != 0 ? RED_PIXEL : GREEN_PIXEL;
            render_rect(&mlx->img, (t_rect){tile_y, tile_x, TILE_SIZE * MINIMAP_SCALE_FACTOR, TILE_SIZE * MINIMAP_SCALE_FACTOR, tile_color});
            */
        }
    }
}

void player_setup(t_player *ppl) {
    ppl->x = WINDOW_WIDTH / 2;
    ppl->y = WINDOW_HEIGHT / 2;
    ppl->width = 1;
    ppl->height = 1;
    ppl->turn_direction = 0;
    ppl->vertical_walk = 0;
    ppl->horizontal_walk = 0;
    ppl->rotation_angle = HALF_PI;
    ppl->walk_speed = 20;
    ppl->turn_speed = 45 * (PI / 180);
}

void    draw_player(t_mlx *mlx, t_player *ppl)
{                                    
    render_rect(&mlx->img, (t_rect){ppl->x, ppl->y, ppl->width, ppl->height, RED_PIXEL});
    draw_line(ppl->x, ppl->y, ppl->x + (cos(ppl->rotation_angle) * 40), ppl->y + (sin(ppl->rotation_angle) * 40), BLACK_PIXEL);
}

int	render(t_mlx *mlx)
{
    if (mlx->mlx_win == NULL)
        return (1);

    //Fundo Tela
    render_background(&mlx->img, WHITE_PIXEL);

    //Map
    draw_map(mlx);

    //Player
    draw_player(mlx, &ppl);

    mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win, mlx->img.mlx_img, 0, 0);
    return (0);
}

void    move_player(t_player *ppl)
{
    float move_step;

    if (ppl->turn_direction)
    {
        //controle da seta
        //Pega angulo de rotação, no ínicio é PI/2 que dá direção central.
        ppl->rotation_angle += ppl->turn_direction * ppl->turn_speed;
    }
    else if (ppl->horizontal_walk)
    {
        //Move_step é a hypotenusa
        move_step = ppl->horizontal_walk * ppl->walk_speed;
        ppl->x += (cos(ppl->rotation_angle + HALF_PI) * move_step);
        ppl->y += (sin(ppl->rotation_angle + HALF_PI) * move_step);
    }
    else if (ppl->vertical_walk)
    {
        //Move_step é a hypotenusa
        move_step = ppl->vertical_walk * ppl->walk_speed;
        ppl->x += (cos(ppl->rotation_angle) * move_step);
        ppl->y += (sin(ppl->rotation_angle) * move_step);
    }
}

int key_up(int keycode, t_player *ppl)
{
    if (keycode == KEY_W)
        ppl->vertical_walk = 0;
    else if (keycode == KEY_S)
        ppl->vertical_walk = 0;
    else if (keycode == KEY_D)
        ppl->horizontal_walk = 0;
    else if (keycode == KEY_A)
        ppl->horizontal_walk = 0;
    else if (keycode == KEY_LEFT_ARROW)
        ppl->turn_direction = 0;
    else if (keycode == KEY_RIGHT_ARROW)
        ppl->turn_direction = 0;
    return (0);
}

int key_down(int keycode, t_player *ppl)
{
    if (keycode == KEY_W)
        ppl->vertical_walk += 1;
    else if (keycode == KEY_S)
        ppl->vertical_walk -= 1;
    else if (keycode == KEY_D)
        ppl->horizontal_walk += 1;
    else if (keycode == KEY_A)
        ppl->horizontal_walk -= 1;
    else if (keycode == KEY_RIGHT_ARROW)
        ppl->turn_direction += 1;
    else if (keycode == KEY_LEFT_ARROW)
        ppl->turn_direction -= 1;
    move_player(ppl);
    render(&mlx);
    return (0);
}

int main(void)
{
	printf("cub3D!\n");
    

    //Player Setup
    player_setup(&ppl);
    
	//Window.
	mlx.mlx_ptr = mlx_init();
	mlx.mlx_win = mlx_new_window(mlx.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "cub3D");

	//Image.
	mlx.img.mlx_img = mlx_new_image(mlx.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	mlx.img.addr = mlx_get_data_addr(mlx.img.mlx_img, &mlx.img.bpp, &mlx.img.line_len, &mlx.img.endian);

    render(&mlx);
    //Input
    mlx_hook(mlx.mlx_win, KEY_PRESS, KEY_PRESS_MASK, &key_down, &ppl);
    mlx_hook(mlx.mlx_win, KEY_RELEASE, KEY_RELEASE_MASK, &key_up, &ppl);


	//Render.
	//mlx_loop_hook(mlx.mlx_ptr, &render, &mlx);

	mlx_loop(mlx.mlx_ptr);
	return (0);
}
