/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 10:52:25 by gialexan          #+#    #+#             */
/*   Updated: 2023/07/18 18:27:22 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef GRAPHICS_H
#define GRAPHICS_H

typedef struct s_line
{
    int x0;
    int y0;
    int x1;
    int y1;
    int color;
}   t_line;

typedef struct s_rect
{
    int	    x;
    int	    y;
    int     width;
    int     height;
    int     color;
}   t_rect;

typedef struct s_image
{
	void	*mlx_img;
    char	*addr;
    int		bpp; /* bits per pixel */
    int		line_len;
    int		endian;
}   t_image;

void    draw_rect(t_image *img, t_rect rect);
void    draw_line(t_image *img, t_line line);
void	draw_background(t_image *img, int color);
void	draw_pixel(t_image *img, unsigned int x, unsigned int y, int color);

#endif