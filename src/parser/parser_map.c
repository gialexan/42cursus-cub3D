/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 12:07:52 by gialexan          #+#    #+#             */
/*   Updated: 2023/08/15 17:58:30 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char		**normalize_map(t_cub3d *cub3d);
static char		**init_norm_map(int rows, int cols);
static t_bool	has_player(t_player *player, char **map);
static t_bool	has_expected(char **map, char *expected);

void	parser_map(t_cub3d *cub3d)
{
	cub3d->map_tmp = read_map(cub3d, cub3d->fd);
	close(cub3d->fd);
	if (!has_expected(cub3d->map_tmp, MAP_VALID_CHAR)
		|| !has_player(&cub3d->player, cub3d->map_tmp))
		cub3d_error(cub3d, PARSER_MAP_ERROR, PARSER_MAP_MSG);
	map_dimensions(cub3d, cub3d->map_tmp);
	cub3d->map = ft_array_dup(cub3d->map_tmp);
	cub3d->map_tmp = normalize_map(cub3d);
	flood_fill(cub3d->map_tmp, cub3d->player.y + 1, cub3d->player.x + 1);
	if (!has_expected(cub3d->map_tmp, FLOOD_FILL_VALID_CHAR))
		cub3d_error(cub3d, PARSER_MAP_ERROR, PARSER_MAP_MSG);
	ft_free_split(cub3d->map_tmp);
}

static t_bool	has_player(t_player *player, char **map)
{
	int x;
	int y;

	y = -1;
	while (map[++y])
	{
		x = -1;
		while(map[y][++x])
		{
			if (ft_strchr(PLAYER_CHAR, map[y][x]))
			{
				if (player->course != NULL_CHAR)
					return (FALSE);
				player->x = x;
				player->y = y;
				player->course = map[y][x];
				map[y][x] = '0';
			}
		}
	}
	return (player->course != NULL_CHAR);
}

static t_bool	has_expected(char **map, char *expected)
{
	int	y;
	int x;

	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (!ft_strchr(expected, map[y][x]))
				return (FALSE);
		}
	}
	return (TRUE);
}

static char	**normalize_map(t_cub3d *cub3d)
{
	int rows;
	int cols;
	char **norm_map;

	rows = cub3d->map_rows;
	cols = cub3d->map_cols;
	rows += 2;
	cols += 2;
	norm_map = init_norm_map(rows, cols);
	copy_map(cub3d->map_tmp, norm_map, rows, cols);
	ft_free_split(cub3d->map_tmp);
	return (norm_map);
}

static char	**init_norm_map(int rows, int cols)
{
	char **map;

	map = malloc((rows + 1) * sizeof(char *));
	for (int i = 0; i < rows; i++)
	{
		map[i] = malloc((cols + 1) * sizeof(char));
		ft_memset(map[i], WHITE_SPACE, cols);
		map[i][cols] = NULL_CHAR;
	}
	map[rows] = NULL;
	return (map);
}