/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 09:36:42 by gialexan          #+#    #+#             */
/*   Updated: 2023/08/08 13:15:31 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

typedef struct s_image	t_image;

typedef struct s_line
{
	int	x0;
	int	y0;
	int	x1;
	int	y1;
	int	color;
	int	delta_x;
	int	delta_y;
	int	longest_side_length;
}	t_line;

typedef struct s_rect
{
	int	x;
	int	y;
	int	width;
	int	height;
	int	color;
}	t_rect;

int		draw_rect(t_image *img, t_rect rect);
void	draw_line(t_image *img, t_line line);
int		encode_rgb(int red, int green, int blue);
void	change_color_intensity(int *color, float factor);
void	draw_pixel(t_image *img, unsigned int x, unsigned int y, int color);

#endif