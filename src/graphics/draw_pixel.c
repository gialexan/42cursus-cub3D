/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 10:46:24 by gialexan          #+#    #+#             */
/*   Updated: 2023/07/18 18:27:39 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

# define TILE_SIZE 64
# define MAP_NUM_ROWS 13
# define MAP_NUM_COLS 20

# define WINDOW_WIDTH (MAP_NUM_COLS * TILE_SIZE)
# define WINDOW_HEIGHT (MAP_NUM_ROWS * TILE_SIZE)

/*
 * cada byte é definido manualmente de maneira diferente, dependendo do endianness.
 * Se você não sabe o que é endianidade, recomendo que leia:
 * https://www.freecodecamp.org/news/what-is-endianness-big-endian-vs-little-endian/
 * 
*/

/*
 * TODO: Gravar dentro da struct t_img o tamanho da imagem para excluir define
*/
void	draw_pixel(t_image *img, unsigned int x, unsigned int y, int color)
{
    char    *pixel;

    if (x > WINDOW_WIDTH || y > WINDOW_HEIGHT)
        return ;
    pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
    *(int *)pixel = color;
}