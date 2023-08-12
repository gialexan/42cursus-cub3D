/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 10:06:34 by gialexan          #+#    #+#             */
/*   Updated: 2023/08/11 12:59:16 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cub3d_error(t_cub3d *cub3d, int errnum, char *msg)
{
	(void)!write(STDERR_FILENO, "cub3D: ", 7);
	ft_putendl_fd(msg, STDERR_FILENO);
	if (errnum == COLOR_BUFFER_MALLOC_ERROR)
		exit_game(cub3d);
	else if (errnum == MLX_INIT_ERROR || errnum == MLX_WINDOW_ERROR)
		destroy_window(&cub3d->window);
	else if ((errnum == TEXTURE_FILE_ERROR)
		|| (errnum == TEXTURE_SIZE_ERROR)
		|| (errnum == TEXTURE_EXTENSION_ERROR))
	{
		destroy_texture(&cub3d->window, cub3d->textures);
		destroy_image(&cub3d->window, &cub3d->image);
		destroy_window(&cub3d->window);
	}
	exit(EXIT_FAILURE);
}
