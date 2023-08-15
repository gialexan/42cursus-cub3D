/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 12:14:33 by gialexan          #+#    #+#             */
/*   Updated: 2023/08/15 12:21:48 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

typedef struct s_cub3d t_cub3d;
typedef enum e_bool t_bool;

char	**read_map(t_cub3d *cub3d, int fd);
t_bool  map_has_wall_at(char **map, float x, float y);
t_bool  check_extension(const char *pathname, const char *extension);
#endif