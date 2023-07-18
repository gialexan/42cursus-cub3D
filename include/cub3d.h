/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 12:03:22 by gialexan          #+#    #+#             */
/*   Updated: 2023/07/18 18:40:26 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CUB3D_H
#define CUB3D_H

#include <math.h>
#include <libft.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>

#include "mlx.h"
#include "window.h"
#include "player.h"
#include "raycast.h"
#include "graphics.h"

typedef struct s_cub3d
{
    t_player    ppl;
    t_image     img;
    t_window    win;
    t_ray       rays[WINDOW_WIDTH];
}   t_cub3d;

#endif