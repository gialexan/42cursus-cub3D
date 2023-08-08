/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 11:39:14 by gialexan          #+#    #+#             */
/*   Updated: 2023/08/08 09:06:50 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void    render_map(t_cub3d *cub3d);
static void    render_rays(t_cub3d *cub3d);
static void    render_player(t_cub3d *cub3d);

void    render_minimap(t_cub3d *cub3d)
{
    render_map(cub3d);
    render_rays(cub3d);
    render_player(cub3d);
}

static void    render_rays(t_cub3d *cub3d)
{
    int i;

    i = 0;
    while (i < NUM_RAYS)
    {
        draw_line(&cub3d->image, (t_line){
                                    MINIMAP_SCALE_FACTOR * cub3d->player.x,
                                    MINIMAP_SCALE_FACTOR * cub3d->player.y,
                                    MINIMAP_SCALE_FACTOR * cub3d->rays[i].wall_hit_x,
                                    MINIMAP_SCALE_FACTOR * cub3d->rays[i].wall_hit_y,
                                    RED_PIXEL});
        i += 50;
    }
}

static void    render_player(t_cub3d *cub3d)
{                                    
    draw_rect(&cub3d->image, (t_rect){
                                MINIMAP_SCALE_FACTOR * cub3d->player.x,
                                MINIMAP_SCALE_FACTOR * cub3d->player.y,
                                MINIMAP_SCALE_FACTOR * cub3d->player.width,
                                MINIMAP_SCALE_FACTOR * cub3d->player.height,
                                RED_PIXEL});
}

static void    render_map(t_cub3d *cub3d)
{
    int x;
    int y;
    int tile_x;
    int tile_y;
    int tile_color;

    y = -1;
    while (++y < MAP_NUM_ROWS)
    {
        x = -1;
        while (++x < MAP_NUM_COLS)
        {
            tile_x = (x * TILE_SIZE);
            tile_y = (y * TILE_SIZE);
            tile_color = BLACK_PIXEL;
            if (cub3d->map.map[y][x] != 0)
                tile_color = WHITE_PIXEL;
            draw_rect(&cub3d->image, (t_rect){
                                            MINIMAP_SCALE_FACTOR * tile_x,
                                            MINIMAP_SCALE_FACTOR * tile_y,
                                            MINIMAP_SCALE_FACTOR * TILE_SIZE,
                                            MINIMAP_SCALE_FACTOR * TILE_SIZE,
                                            tile_color});
        }
    }
}