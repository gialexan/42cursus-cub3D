/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rectangle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 09:44:30 by gialexan          #+#    #+#             */
/*   Updated: 2023/07/19 13:08:07 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
 * Primeiro parametro ponteiro img da mlx
 * Segundo e terceiro parametro x, y parametro 
 * Terceiro parametro width -> largura
 * Quarto parametro height -> altura
 * Quinto parametro cor
*/

int draw_rect(t_image *img, t_rect rect)
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
