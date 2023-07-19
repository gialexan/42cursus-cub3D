/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 13:16:38 by gialexan          #+#    #+#             */
/*   Updated: 2023/07/19 13:35:17 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef RENDER_H
#define RENDER_H

typedef struct s_image t_image;
typedef struct s_cub3d t_cub3d;

void    render_map(t_cub3d *cub3d);
int     render_game(t_cub3d *cub3d);
void    render_rays(t_cub3d *cub3d);
void    render_player(t_cub3d *cub3d);
void	render_background(t_image *img, int color);

#endif
