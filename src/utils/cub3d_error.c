/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 10:06:34 by gialexan          #+#    #+#             */
/*   Updated: 2023/08/16 14:26:06 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cub3d_error(t_cub3d *cub3d, int errnum, char *msg)
{
	(void)!write(STDERR_FILENO, "cub3D: ", 7);
	ft_putendl_fd(msg, STDERR_FILENO);
	if (errnum == COLOR_BUFFER_MALLOC_ERROR)
		exit_game(cub3d);
	else if (errnum == PARSER_COLOR_ERROR || errnum == PARSER_TEXTURE_ERROR
		|| errnum == FILE_SETTING_ERROR || errnum == TEXTURE_EXTENSION_ERROR)
		flush_gnl(cub3d->fd);
	else if (errnum == MLX_WINDOW_ERROR || errnum == MLX_IMAGE_ERROR)
	{
		ft_free_split(cub3d->map);
		destroy_window(&cub3d->window);
	}
	else if (errnum == TEXTURE_SIZE_ERROR)
	{
		ft_free_split(cub3d->map);
		destroy_texture(&cub3d->window, cub3d->textures);
		destroy_image(&cub3d->window, &cub3d->image);
		destroy_window(&cub3d->window);
	}
	else if (errnum == PARSER_MAP_ERROR || errnum == NORM_MAP_ERROR)
	{
		ft_free_split(cub3d->map);
		ft_free_split(cub3d->map_tmp);
	}
	exit(EXIT_FAILURE);
}
