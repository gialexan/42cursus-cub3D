/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 11:05:57 by gialexan          #+#    #+#             */
/*   Updated: 2023/07/31 11:06:53 by gialexan         ###   ########.fr       */
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
    char	*addr;
    char    *path;
    int		bpp;
    int		line_len;
    int		endian;
    int     width;
    int     height;
}   t_texture;


#endif