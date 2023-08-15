/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 19:08:50 by gialexan          #+#    #+#             */
/*   Updated: 2023/08/15 18:12:01 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

typedef struct s_cub3d t_cub3d;
typedef struct s_texture t_texture;

void	jump_line(t_cub3d *cub3d);
void	parser_map(t_cub3d *cub3d);
void    parser_cubfile(t_cub3d *cub3d);
void	map_dimensions(t_cub3d *cub3d, char **map);
t_bool  is_valid_floor(char **map, int row, int col);
void    flood_fill(char **map_dup, int row, int col);
void    open_cubfile(t_cub3d *cub3d, const char *pathname);
void	copy_map(char **map, char **norm_map, int rows, int cols);
void	parser_color(t_cub3d *cub3d, t_rgb *color, char *expected);
void    parser_texture(t_cub3d *cub3d, t_texture *texture, char *expected);

#endif