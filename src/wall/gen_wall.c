/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_wall.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:03:58 by gialexan          #+#    #+#             */
/*   Updated: 2023/07/25 17:04:14 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    generate_wall(t_cub3d *cub3d, t_gen3d *gen3d, int x)
{
    int y;

    y = gen3d->wall_top_pixel;
    while (y++ < gen3d->wall_bottom_pixel)
        cub3d->color_buffer[(WINDOW_WIDTH * y) + x] = 0xFFCCCCCC;
}