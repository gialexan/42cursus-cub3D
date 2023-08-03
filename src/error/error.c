/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 10:06:34 by gialexan          #+#    #+#             */
/*   Updated: 2023/08/03 09:14:14 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void    cub3d_errmsg(char *msg);

void    cub3d_error(t_cub3d *cub3d, int errnum, char *msg)
{
    if (errnum == MLX_INIT_ERROR || errnum == MLX_WINDOW_ERROR)
        cub3d_errmsg(msg);
    else if (errnum == TEXTURE_PATH_ERROR || errnum == TEXTURE_SIZE_ERROR || errnum == TEXTURE_EXTENSION_ERROR)
    {
        destroy_texture(&cub3d->window, cub3d->textures);
        destroy_window(&cub3d->window);
        destroy_display(&cub3d->window);
        cub3d_errmsg(msg);
    }
}

static void    cub3d_errmsg(char *msg)
{
    ft_putendl_fd(msg, 2);
    exit(1);
}
