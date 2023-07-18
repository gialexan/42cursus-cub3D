/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 16:30:34 by gialexan          #+#    #+#             */
/*   Updated: 2023/07/18 17:32:36 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef WINDOW_H
#define WINDOW_H

#include "graphics.h"

typedef struct s_window
{
	void	*mlx_ptr;
	void	*mlx_win;
    int     window_width;
    int     window_height;
}	t_window;

#endif