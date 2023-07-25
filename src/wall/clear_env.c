/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 16:55:39 by gialexan          #+#    #+#             */
/*   Updated: 2023/07/25 16:56:05 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void clear_env(t_cub3d *cub3d)
{
    for (int x = 0; x < WINDOW_WIDTH; x++)
        for (int y = 0; y < WINDOW_HEIGHT; y++)
            cub3d->color_buffer[(WINDOW_WIDTH * y) + x] = BLACK_PIXEL;
}