/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_direction.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 09:54:30 by gialexan          #+#    #+#             */
/*   Updated: 2023/07/28 15:45:04 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_bool	is_raydir_down(float angle)
{
	return (angle > 0 && angle < PI);
}

t_bool	is_raydir_up(float angle)
{
	return (!is_raydir_down(angle));
}

t_bool	is_raydir_right(float angle)
{
	return ((angle < 0.5 * PI) || (angle > 1.5 * PI));
}

t_bool	is_raydir_left(float angle)
{
	return (!is_raydir_right(angle));
}
