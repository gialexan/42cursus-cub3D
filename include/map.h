/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 19:08:50 by gialexan          #+#    #+#             */
/*   Updated: 2023/08/11 20:37:14 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

typedef enum s_compass
{
	NORTH,
	EAST,
	WEST,
	SOUTH,
}	t_compass;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_map
{
	char		**tmp;
	char		*no_path;
	char		*so_path;
	char		*we_path;
	char		*ea_path;
    t_color     ceil;
	t_color		floor;
	t_compass	player_course;
}	t_map;

char	**read_map(int fd);
void    flood_fill(char **map_dup, int row, int col);


#endif