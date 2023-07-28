/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 16:55:39 by gialexan          #+#    #+#             */
/*   Updated: 2023/07/28 16:18:36 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void clear_env(t_cub3d *cub3d)
{
    int x;
    int y;


    y = -1;
    while (++y < WINDOW_HEIGHT)
    {
        x = -1;
        while (++x < WINDOW_WIDTH)
            cub3d->color_buffer[(WINDOW_WIDTH * y) + x] = BLACK_PIXEL;
    }
}
