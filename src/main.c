/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 18:55:29 by gialexan          #+#    #+#             */
/*   Updated: 2023/07/14 18:03:32 by gialexan         ###   ########.fr       */
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

# define TILE_SIZE 64
# define MAP_NUM_ROWS 13
# define MAP_NUM_COLS 20

# define WINDOW_WIDTH (MAP_NUM_COLS * TILE_SIZE)
# define WINDOW_HEIGHT (MAP_NUM_ROWS * TILE_SIZE)

# define MINIMAP_SCALE_FACTOR 0.3
# define NUM_RAYS WINDOW_WIDTH


typedef struct s_intersection
{
    float   wall_hit_x;
    float   wall_hit_y;
    t_bool  found_wall_hit;
    int     wall_content;
}   t_intersection;

typedef struct s_ray
{
    float   ray_angle;
    float   wall_hit_x;
    float   wall_hit_y;
    float   distance;
    t_bool     was_hit_vertical;
    t_bool     is_ray_facing_up;
    t_bool     is_ray_facing_down;
    t_bool     is_ray_facing_left;
    t_bool     is_ray_facing_right;
    t_bool     wall_hit_content;
}   t_ray;

typedef struct s_rect
{
    int	    x;
    int	    y;
    int     width;
    int     height;
    int     color;
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


t_ray       ray[NUM_RAYS];
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
void	draw_pixel(t_img *img, unsigned int x, unsigned int y, int color)
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
        draw_pixel(&mlx.img, round(currentX), round(currentY), color);
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
            draw_pixel(img, j++, i, color);
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
int draw_rect(t_img *img, t_rect rect)
{
    int	i;
    int j;

    i = rect.y;
    while (i < rect.y + rect.height)
    {
        j = rect.x;
        while (j < rect.x + rect.width)
            draw_pixel(img, j++, i, rect.color);
        ++i;
    }
    return (0);
}

float    normalize_angle(float angle)
{
    angle = remainder(angle, TWO_PI);
    if (angle < 0)
        angle = TWO_PI + angle;
    return (angle);
}

t_bool	is_ray_facing_down(float angle)
{
	return (angle > 0 && angle < PI);
}

t_bool	is_ray_facing_up(float angle)
{
	return (!is_ray_facing_down(angle));
}

t_bool	is_ray_facing_right(float angle)
{
	return (angle < (0.5 * PI) || angle > (1.5 * PI));
}

t_bool	is_ray_facing_left(float angle)
{
	return (!is_ray_facing_right(angle));
}

float   find_y_horizontal_intersection(t_player *ppl)
{
    return (floor(ppl->y / TILE_SIZE) * TILE_SIZE);
}

float find_x_horizontal_intersection(t_player *ppl, float y_intercept, float angle)
{
    return (ppl->x + ((y_intercept - ppl->y) / tan(angle)));
}

float   increment_y_horizontal_intersection(float *y_intercept, float angle)
{
    if (is_ray_facing_down(angle))
        *y_intercept += TILE_SIZE;
}

void    horizontal_intersection(t_player *ppl, t_intersection *horz, float ray_angle)
{
    float x_step;
    float y_step;
    float x_intercept;
    float y_intercept;

    y_intercept = find_y_horizontal_intersection(ppl);
    increment_y_horizontal_intersection(&y_intercept, ray_angle);
    x_intercept = find_x_horizontal_intersection(ppl, y_intercept, ray_angle);
}


void    cast_ray(float ray_angle, int column_id)
{
    t_intersection  horz;
    
    ray_angle = normalize_angle(ray_angle);
    horizontal_intersection(&ppl, &horz, ray_angle);
    //find_ray_direction(&intersec, ray_angle);
}

void    cast_all_rays(t_player *ppl)
{
    int     column_id;
    float   ray_angle;

    column_id = -1;
    ray_angle = ppl->rotation_angle - (FOV_ANGLE / 2);
    while (++column_id < NUM_RAYS)
    {
        cast_ray(ray_angle, column_id);
        ray_angle += FOV_ANGLE / NUM_RAYS;
    }
}

void    render_map(t_mlx *mlx)
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
            draw_rect(&mlx->img, (t_rect){tile_x, tile_y, TILE_SIZE - 1, TILE_SIZE - 1, tile_color});


            /* Minimap
            tile_x = (x * TILE_SIZE) * MINIMAP_SCALE_FACTOR;
            tile_y = (y * TILE_SIZE) * MINIMAP_SCALE_FACTOR;
            tile_color = map[x][y] != 0 ? RED_PIXEL : GREEN_PIXEL;
            draw_rect(&mlx->img, (t_rect){tile_y, tile_x, TILE_SIZE * MINIMAP_SCALE_FACTOR, TILE_SIZE * MINIMAP_SCALE_FACTOR, tile_color});
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
    ppl->rotation_angle = (PI / 2);
    ppl->walk_speed = 10;
    ppl->turn_speed = 45 * (PI / 180);
}

void    render_player(t_mlx *mlx, t_player *ppl)
{                                    
    draw_rect(&mlx->img, (t_rect){ppl->x, ppl->y, ppl->width, ppl->height, RED_PIXEL});
    draw_line(ppl->x, ppl->y, ppl->x + (cos(ppl->rotation_angle) * 40), ppl->y + (sin(ppl->rotation_angle) * 40), BLACK_PIXEL);
}

int	render(t_mlx *mlx)
{
    if (mlx->mlx_win == NULL)
        return (1);

    //Fundo Tela
    render_background(&mlx->img, WHITE_PIXEL);

    //Map
    render_map(mlx);

    //Player
    render_player(mlx, &ppl);

    mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win, mlx->img.mlx_img, 0, 0);
    return (0);
}

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

void    player_direction(t_player *ppl)
{
    float new_ppl_x;
    float new_ppl_y;
    float hypotenuse;

    if (ppl->turn_direction)
    {
        //controle da seta
        //Pega angulo de rotação, no ínicio é PI/2 que dá direção central.
        ppl->rotation_angle += ppl->turn_direction * ppl->turn_speed;
        //sem necessidade talvez
        //normalize_angle(&ppl->rotation_angle);
    }
    else if (ppl->horizontal_walk)
    {
        hypotenuse = ppl->horizontal_walk * ppl->walk_speed;
        new_ppl_x = ppl->x + (cos(ppl->rotation_angle + HALF_PI) * hypotenuse);
        new_ppl_y = ppl->y + (sin(ppl->rotation_angle + HALF_PI) * hypotenuse);
    }
    else if (ppl->vertical_walk)
    {
        hypotenuse = ppl->vertical_walk * ppl->walk_speed;
        new_ppl_x = ppl->x + (cos(ppl->rotation_angle) * hypotenuse);
        new_ppl_y = ppl->y + (sin(ppl->rotation_angle) * hypotenuse);
    }
    if (!map_has_wall_at(new_ppl_x, new_ppl_y))
    {
        ppl->x = new_ppl_x;
        ppl->y = new_ppl_y;
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
    //ray_direction(ppl);
    player_direction(ppl);
    //cast_all_rays(ppl);
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
