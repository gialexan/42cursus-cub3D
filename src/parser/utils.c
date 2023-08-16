/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 14:42:49 by gialexan          #+#    #+#             */
/*   Updated: 2023/08/16 17:03:29 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	open_cubfile(t_cub3d *cub3d, const char *pathname)
{
	int	fd;

	if (!check_extension(pathname, MAP_EXTENSION))
		cub3d_error(NULL, FILE_EXTENSION_ERROR, FILE_EXTENSION_MSG);
	fd = open(pathname, O_RDONLY);
	if (fd == -1)
		cub3d_error(NULL, FILE_FILE_ERROR, FILE_FILE_MSG);
	cub3d->fd = fd;
}

void	jump_line(t_cub3d *cub3d)
{
	char	*read_line;

	read_line = gnl(cub3d->fd);
	if (*read_line != '\n')
	{
		free(read_line);
		cub3d_error(cub3d, FILE_SETTING_ERROR, FILE_SETTING_MSG);
	}
	free(read_line);
}

void	map_dimensions(t_cub3d *cub3d, char **map)
{
	int	total_cols;
	int	total_rows;

	total_cols = 0;
	total_rows = 0;
	while (map[total_rows])
	{
		total_rows++;
		if ((int)ft_strlen(map[total_rows - 1]) > total_cols)
			total_cols = ft_strlen(map[total_rows - 1]);
	}
	cub3d->map_cols = total_cols;
	cub3d->map_rows = total_rows;
}

t_bool	is_valid_floor(char **map, int row, int col)
{
	char	cell;

	cell = map[row][col];
	if (cell == ' ')
		map[row][col] = '#';
	if (cell == ' ' || cell == '\0')
		return (FALSE);
	if (cell == '1' || cell == '@' || cell == '!')
		return (FALSE);
	return (TRUE);
}

void	copy_map(char **map, char **norm_map, int rows, int cols)
{
	int	y;
	int	x;

	y = 1;
	while (y < (rows - 1))
	{
		x = 1;
		while (x < (cols - 1) && map[y - 1][x - 1] != '\0')
		{
			norm_map[y][x] = map[y - 1][x - 1];
			x++;
		}
		y++;
	}
}
