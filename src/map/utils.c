/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 14:42:49 by gialexan          #+#    #+#             */
/*   Updated: 2023/08/14 21:21:29 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    load_cubfile(t_cub3d *cub3d, const char *pathname)
{
	int fd;

	if (!check_extension(pathname, MAP_EXTENSION))
		cub3d_error(NULL, FILE_EXTENSION_ERROR, FILE_EXTENSION_MSG);
	fd = open(pathname, O_RDONLY);
	if (fd == -1)
		cub3d_error(NULL, FILE_FILE_ERROR, FILE_FILE_MSG);
	cub3d->fd = fd;
}

t_bool check_extension(const char *pathname, const char *extension)
{
	const char *file_ext;

	file_ext = ft_strrchr(pathname, '.');
	if (file_ext)
	{
		file_ext++;
		if (ft_strncmp(file_ext, extension, ft_strlen(extension) + 1) == 0)
			return (TRUE);
	}
	return (FALSE);
}

void	jump_line(t_cub3d *cub3d)
{
	char *read_line;

	read_line = gnl(cub3d->fd);
	if (*read_line != CHAR_LINE_BREAK)
	{
		free(read_line);
		cub3d_error(cub3d, FILE_SETTING_ERROR, FILE_SETTING_MSG);
	}
}