/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 13:50:09 by gialexan          #+#    #+#             */
/*   Updated: 2023/08/08 13:06:45 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

typedef struct s_image	t_image;
typedef struct s_cub3d	t_cub3d;

typedef struct s_window
{
	void	*mlx_ptr;
	void	*mlx_win;
	int		widht;
	int		height;
}	t_window;

void	init_window(t_cub3d *cub3d);
void	destroy_window(t_window *window);

#endif