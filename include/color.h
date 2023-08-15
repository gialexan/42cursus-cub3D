/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 11:53:59 by gialexan          #+#    #+#             */
/*   Updated: 2023/08/15 12:05:08 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

typedef enum s_color
{
    FLOOR,
    CEIL
}   t_color;

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}	t_rgb;

int     encode_rgb(int red, int green, int blue);
void	change_color_intensity(int *color, float factor);

#endif