/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 10:06:34 by gialexan          #+#    #+#             */
/*   Updated: 2023/08/07 18:14:18 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    cub3d_error(t_cub3d *cub3d, int errnum, char *msg)
{
    ft_putendl_fd(msg, STDERR_FILENO);
    if (errnum == MLX_INIT_ERROR || errnum == MLX_WINDOW_ERROR)
        destroy_window(&cub3d->window);
    else if ((errnum == TEXTURE_PATH_ERROR)
        || (errnum == TEXTURE_SIZE_ERROR )
        || (errnum == TEXTURE_EXTENSION_ERROR))
    {
        destroy_texture(&cub3d->window, cub3d->textures);
        destroy_image(&cub3d->window, &cub3d->image);
        destroy_window(&cub3d->window);
    }
    exit(1);
}
