/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 09:42:56 by gialexan          #+#    #+#             */
/*   Updated: 2023/07/31 15:31:51 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void draw_line(t_image *img, t_line line)
{
    int     i;
    int     delta_x;
    int     delta_y;
    float   current_x;
    float   current_y;
    float   x_increment;
    float   y_increment;
    int     longest_side_length;

    i = -1;
    delta_x = (line.x1 - line.x0);
    delta_y = (line.y1 - line.y0);
    longest_side_length = abs(delta_y);
    if (abs(delta_x) >= abs(delta_y))
        longest_side_length = abs(delta_x);
    x_increment = delta_x / (float)longest_side_length;
    y_increment = delta_y / (float)longest_side_length;
    current_x = line.x0;
    current_y = line.y0;
    while (++i < longest_side_length)
    {
        draw_pixel(img, round(current_x), round(current_y), line.color);
        current_x += x_increment;
        current_y += y_increment;
    }
}
