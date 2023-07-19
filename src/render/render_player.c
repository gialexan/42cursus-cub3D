/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 13:15:07 by gialexan          #+#    #+#             */
/*   Updated: 2023/07/19 13:16:02 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    render_player(t_cub3d *cub3d)
{                                    
    draw_rect(&cub3d->image, (t_rect){
                                cub3d->player.x,
                                cub3d->player.y,
                                cub3d->player.width,
                                cub3d->player.height,
                                RED_PIXEL});
    draw_line(&cub3d->image, (t_line){
                                cub3d->player.x,
                                cub3d->player.y,
                                cub3d->player.x + (cos(cub3d->player.rotation_angle) * 40),
                                cub3d->player.y + (sin(cub3d->player.rotation_angle) * 40),
                                BLACK_PIXEL});
}
