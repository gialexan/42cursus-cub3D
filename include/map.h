/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 19:08:50 by gialexan          #+#    #+#             */
/*   Updated: 2023/08/14 18:40:07 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

typedef enum e_bool t_bool;
typedef struct s_cub3d t_cub3d;
typedef struct s_texture t_texture;

typedef enum s_compass
{
	NORTH,
	SOUTH,
	WEST,
	EAST,
	COUNT
}	t_compass;

typedef enum s_color
{
    FLOOR,
    CEIL
}   t_color;

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}	t_rgb;

typedef struct s_map
{
	char		**map;
	int			fd;
	char		*no_path;
	char		*so_path;
	char		*we_path;
	char		*ea_path;
	t_rgb		floor;
    t_rgb 		ceil;
	t_compass	player_course;
}	t_map;

void	jump_line(t_cub3d *cub3d);
char	**read_map(t_cub3d *cub3d, int fd);
void    flood_fill(char **map_dup, int row, int col);
void    load_cubfile(t_cub3d *cub3d, const char *pathname);
void	parser_color(t_cub3d *cub3d, t_rgb *color, char *expected);
t_bool	check_extension(const char *pathname, const char *extension);
void    parser_texture(t_cub3d *cub3d, t_texture *texture, char *expected);

#endif