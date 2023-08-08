/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 13:16:38 by gialexan          #+#    #+#             */
/*   Updated: 2023/08/08 13:07:32 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

typedef struct s_cub3d	t_cub3d;

int		render_game(t_cub3d *cub3d);
void	render_env3d(t_cub3d *cub3d);
void	render_minimap(t_cub3d *cub3d);

#endif
