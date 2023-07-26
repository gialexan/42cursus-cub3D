/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 13:50:09 by gialexan          #+#    #+#             */
/*   Updated: 2023/07/26 17:49:19 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef WINDOW_H
#define WNIDOW_H

typedef struct s_image t_image;

typedef struct s_window
{
	void	*mlx_ptr;
	void	*mlx_win;
	int		win_widht;
	int		win_height;
}	t_window;

void    init_window(t_window *window);
void    create_image(t_window *window, t_image *image);

#endif