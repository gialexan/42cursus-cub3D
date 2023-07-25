/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 17:51:56 by gialexan          #+#    #+#             */
/*   Updated: 2023/07/25 14:27:59 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef WALL_H
#define WALL_H

typedef struct s_cub3d t_cub3d;

typedef struct s_gen3d
{
    int     wall_height;
    int     wall_top_pixel;
    int     wall_bottom_pixel;
}   t_gen3d;

void    gen3d_env(t_cub3d *cub3d);

#endif