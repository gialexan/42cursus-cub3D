/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_floor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:03:16 by gialexan          #+#    #+#             */
/*   Updated: 2023/07/31 13:17:58 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//0xFF333333
void    generate_floor(t_cub3d *cub3d, int wall_bottom_pixel, int x)
{
    int y;

    y = wall_bottom_pixel;
    while (y < cub3d->window.height)
        cub3d->color_buffer[(cub3d->window.widht * y++) + x] = BLACK_PIXEL;
}
