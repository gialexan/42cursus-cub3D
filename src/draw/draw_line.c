/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 09:42:56 by gialexan          #+#    #+#             */
/*   Updated: 2023/08/08 13:04:16 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_line(t_image *img, t_line line)
{
	int		i;
	float	current_x;
	float	current_y;
	float	x_increment;
	float	y_increment;

	i = -1;
	line.delta_x = (line.x1 - line.x0);
	line.delta_y = (line.y1 - line.y0);
	line.longest_side_length = abs(line.delta_y);
	if (abs(line.delta_x) >= abs(line.delta_y))
		line.longest_side_length = abs(line.delta_x);
	x_increment = line.delta_x / (float)line.longest_side_length;
	y_increment = line.delta_y / (float)line.longest_side_length;
	current_x = line.x0;
	current_y = line.y0;
	while (++i < line.longest_side_length)
	{
		draw_pixel(img, round(current_x), round(current_y), line.color);
		current_x += x_increment;
		current_y += y_increment;
	}
}
