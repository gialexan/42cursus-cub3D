/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 19:08:50 by gialexan          #+#    #+#             */
/*   Updated: 2023/08/13 16:13:10 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

typedef enum s_compass
{
	NORTH,
	SOUTH,
	WEST,
	EAST,
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
    char		**tmp;
	char		*no_path;
	char		*so_path;
	char		*we_path;
	char		*ea_path;
	t_rgb		floor;
    t_rgb     ceil;
	t_compass	player_course;
}	t_map;

char	**read_map(int fd);
void    flood_fill(char **map_dup, int row, int col);


#endif