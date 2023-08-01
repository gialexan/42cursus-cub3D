/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 12:45:26 by gialexan          #+#    #+#             */
/*   Updated: 2023/08/01 19:34:45 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void    load_texture_data(t_texture *texture, t_window *window, char *path);

//TODO: Vai carregar as texturas do mapa.
//Se textura for maior 64x64 retorna erro.
//Se textura for inválida retorna erro.
void    load_texture(t_cub3d *cub3d)
{
    load_texture_data(&cub3d->textures[WEST], &cub3d->window, cub3d->map.we_path);
    load_texture_data(&cub3d->textures[EAST], &cub3d->window, cub3d->map.ea_path);
    load_texture_data(&cub3d->textures[NORTH], &cub3d->window, cub3d->map.no_path);
    load_texture_data(&cub3d->textures[SOUTH], &cub3d->window, cub3d->map.so_path);
}

void    destroy_texture(t_window *window, t_texture *textures)
{
    int i;

    i = -1; 
    while (++i < 4)
        mlx_destroy_image(window->mlx_ptr, textures[i].img_ptr);
}

static void load_texture_data(t_texture *texture, t_window *window, char *path)
{
    texture->img_ptr = mlx_xpm_file_to_image(window->mlx_ptr, path, &texture->width, &texture->height);
    texture->addr = (int *) mlx_get_data_addr(texture->img_ptr, &texture->bpp, &texture->line_len, &texture->endian);
}
