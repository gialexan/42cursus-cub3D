/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rectangle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 10:48:19 by gialexan          #+#    #+#             */
/*   Updated: 2023/07/18 18:27:42 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

/*
 * Primeiro parametro ponteiro img da mlx
 * Segundo e terceiro parametro x, y parametro 
 * Terceiro parametro width -> largura
 * Quarto parametro height -> altura
 * Quinto parametro cor
*/
void draw_rect(t_image *img, t_rect rect)
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
}