/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 18:55:29 by gialexan          #+#    #+#             */
/*   Updated: 2023/07/10 10:40:18 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
 * 1 byte = 8 bits
 * 1 pixel = 32 bits
 * 32 bits / 8 = 4 bytes.
 * 4 bytes por pixel.
*/

#define WINDOW_WIDTH 600 //colunas
#define WINDOW_HEIGHT 300 //linhas

#define MLX_ERROR 1

#define RED_PIXEL 0xFF0000
#define GREEN_PIXEL 0xFF00
#define WHITE_PIXEL 0xFFFFFF

typedef struct s_rect
{
    int	x;
    int	y;
    int width;
    int height;
    int color;
}	t_rect;

typedef struct s_img
{
	void	*mlx_img;
    char	*addr;
    int		bpp; /* bits per pixel */
    int		line_len;
    int		endian;
} t_img;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*mlx_win;
	t_img	img;
}	t_mlx;

/*
 * cada byte é definido manualmente de maneira diferente, dependendo do endianness. 
 * Se você não sabe o que é endianidade, recomendo que leia:
 * https://www.freecodecamp.org/news/what-is-endianness-big-endian-vs-little-endian/
*/
void	img_pix_put(t_img *img, int x, int y, int color)
{
    char    *pixel;

    pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
    *(int *)pixel = color;
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

int y = 0; //linha
int x = 0; //coluna

int	render(t_mlx *mlx)
{
    if (mlx->mlx_win == NULL)
        return (1);
    if (y <= WINDOW_HEIGHT - 50 && x <= WINDOW_WIDTH - 50)
    {
        render_background(&mlx->img, WHITE_PIXEL);
        render_rect(&mlx->img, (t_rect){x, y, 50, 50, RED_PIXEL});
        mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win, mlx->img.mlx_img, 0, 0);
        y++;
        x++;
        printf("Value x: %d ", x);
        printf("Value y: %d\n", y);
        usleep(5000);
    }
    return (0);
}

int main(void)
{
	t_mlx	mlx;

	printf("cub3D!\n");

	//Window.
	mlx.mlx_ptr = mlx_init();
	mlx.mlx_win = mlx_new_window(mlx.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "cub3D");
	
	//Image.
	mlx.img.mlx_img = mlx_new_image(mlx.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	mlx.img.addr = mlx_get_data_addr(mlx.img.mlx_img, &mlx.img.bpp, &mlx.img.line_len, &mlx.img.endian);

	//Loop render.
	mlx_loop_hook(mlx.mlx_ptr, &render, &mlx);
	//mlx_key_hook(mlx.mlx_ptr, NULL, &mlx);
	
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
