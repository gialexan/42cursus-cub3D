/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 09:43:38 by gialexan          #+#    #+#             */
/*   Updated: 2023/07/19 12:25:50 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
 * cada byte é definido manualmente de maneira diferente, dependendo do endianness.
 * Se você não sabe o que é endianidade, recomendo que leia:
 * https://www.freecodecamp.org/news/what-is-endianness-big-endian-vs-little-endian/
 * 
*/
void	draw_pixel(t_image *img, unsigned int x, unsigned int y, int color)
{
    char    *pixel;

    if (x > WINDOW_WIDTH || y > WINDOW_HEIGHT)
        return ;
    pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
    *(int *)pixel = color;
}
