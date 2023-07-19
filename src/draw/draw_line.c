/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 09:42:56 by gialexan          #+#    #+#             */
/*   Updated: 2023/07/19 12:25:52 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void draw_line(t_image *img, t_line line)
{
    int deltaX = (line.x1 - line.x0);
    int deltaY = (line.y1 - line.y0);

    int longestSideLength = (abs(deltaX) >= abs(deltaY)) ? abs(deltaX) : abs(deltaY);

    float xIncrement = deltaX / (float)longestSideLength;
    float yIncrement = deltaY / (float)longestSideLength;

    float currentX = line.x0;
    float currentY = line.y0;

    for (int i = 0; i < longestSideLength; i++) {
        draw_pixel(img, round(currentX), round(currentY), line.color);
        currentX += xIncrement;
        currentY += yIncrement;
    }
}
