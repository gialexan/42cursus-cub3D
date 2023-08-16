/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 19:08:50 by gialexan          #+#    #+#             */
/*   Updated: 2023/08/16 16:59:41 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

typedef struct s_cub3d		t_cub3d;
typedef struct s_texture	t_texture;

/***************************************************************************\
 * PARSER/FLOOD_FILL.C
\***************************************************************************/

void	flood_fill(char **map_dup, int row, int col);

/***************************************************************************\
 * PARSER/FLOOD_FILL
\***************************************************************************/

void	parser_color(t_cub3d *cub3d, t_rgb *color, char *expected);

/***************************************************************************\
 * PARSER/CUBFILE.C
\***************************************************************************/

void	parser_cubfile(t_cub3d *cub3d);

/***************************************************************************\
 * PARSER/PARSER_MAP.C
\***************************************************************************/

void	parser_map(t_cub3d *cub3d);

/***************************************************************************\
 * PARSER/PARSER_TEXTURE.C
\***************************************************************************/

void	parser_texture(t_cub3d *cub3d, t_texture *texture, char *expected);

/***************************************************************************\
 * PARSER/UTILS.C
\***************************************************************************/

void	jump_line(t_cub3d *cub3d);
void	map_dimensions(t_cub3d *cub3d, char **map);
t_bool	is_valid_floor(char **map, int row, int col);
void	open_cubfile(t_cub3d *cub3d, const char *pathname);
void	copy_map(char **map, char **norm_map, int rows, int cols);

#endif