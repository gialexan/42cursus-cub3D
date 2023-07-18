/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_background.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 10:50:42 by gialexan          #+#    #+#             */
/*   Updated: 2023/07/18 18:27:32 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

# define TILE_SIZE 64
# define MAP_NUM_ROWS 13
# define MAP_NUM_COLS 20

# define WINDOW_WIDTH (MAP_NUM_COLS * TILE_SIZE)
# define WINDOW_HEIGHT (MAP_NUM_ROWS * TILE_SIZE)

/*
 * TODO: Gravar dentro da struct t_img o tamanho da imagem para excluir define
*/
void	draw_background(t_image *img, int color)
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