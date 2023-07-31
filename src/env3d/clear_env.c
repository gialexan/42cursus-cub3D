/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 16:55:39 by gialexan          #+#    #+#             */
/*   Updated: 2023/07/31 13:17:30 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void clear_env(t_cub3d *cub3d)
{
    int x;
    int y;

    x = -1;
    while (++x < cub3d->window.widht)
    {
        y = -1;
        while (++y < cub3d->window.height)
            cub3d->color_buffer[(cub3d->window.widht * y) + x] = BLACK_PIXEL;
    }
}
