/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_intensity.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 11:19:47 by gialexan          #+#    #+#             */
/*   Updated: 2023/08/07 09:58:47 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    change_color_intensity(int *color, float factor)
{
    int a;
    int r;
    int g;
    int b;

    a = (*color & 0xFF000000);
    r = (*color & 0x00FF0000) * factor;
    g = (*color & 0x0000FF00) * factor;
    b = (*color & 0xFF0000FF) * factor;
    *color = a | (r & 0x00FF0000) | (g & 0x0000FF00) | (b & 0xFF0000FF);
}
