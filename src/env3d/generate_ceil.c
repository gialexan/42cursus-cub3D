/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_ceil.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:01:24 by gialexan          #+#    #+#             */
/*   Updated: 2023/07/29 09:56:21 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//0xFF666666
void    generate_ceil(t_cub3d *cub3d, int wall_top_pixel, int x)
{
    int y;

    y = 0;
    while (y < wall_top_pixel)
        cub3d->color_buffer[(WINDOW_WIDTH * y++) + x] = BLACK_PIXEL;
}
