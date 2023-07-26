/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_floor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:03:16 by gialexan          #+#    #+#             */
/*   Updated: 2023/07/25 21:18:34 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    generate_floor(t_cub3d *cub3d, int wall_bottom_pixel, int x)
{
    int y;

    y = wall_bottom_pixel;
    while (++y < WINDOW_HEIGHT)
        cub3d->color_buffer[(WINDOW_WIDTH * y) + x] = 0xFF666666;
}