/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 11:05:57 by gialexan          #+#    #+#             */
/*   Updated: 2023/08/01 14:49:13 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef TEXTURES_H
#define TEXTURES_H

typedef enum s_compass
{
    NORTH,
    EAST,
    WEST,
    SOUTH,
}   t_compass;

typedef struct s_texture
{
	void	*img_ptr;
    int 	*addr;
    int		bpp;
    int		line_len;
    int		endian;
    int     width;
    int     height;
}   t_texture;

void    load_texture(t_cub3d *cub3d);


#endif