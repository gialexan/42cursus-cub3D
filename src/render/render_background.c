/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_background.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 12:25:04 by gialexan          #+#    #+#             */
/*   Updated: 2023/07/29 10:02:13 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_background(t_image *img, int color)
{
    int	i;
    int	j;

    i = -1;
    while (++i < WINDOW_HEIGHT)
    {
        j = -1;
        while (++j < WINDOW_WIDTH)
            draw_pixel(img, j, i, color);
    }
}
