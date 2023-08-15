/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 11:05:57 by gialexan          #+#    #+#             */
/*   Updated: 2023/08/15 18:56:59 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_H
# define TEXTURE_H

# define BUFFER 1024

typedef enum s_compass
{
	NORTH,
	SOUTH,
	WEST,
	EAST,
	COUNT
}	t_compass;

typedef struct s_texture
{
	char	pathname[BUFFER];
	void	*img_ptr;
	int		*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}	t_texture;

/***************************************************************************\
 * TEXTURE/TEXTURE.C
\***************************************************************************/

void	load_texture(t_cub3d *cub3d);
void	destroy_texture(t_window *window, t_texture *texture);

#endif