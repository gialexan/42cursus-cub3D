/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 11:29:03 by gialexan          #+#    #+#             */
/*   Updated: 2023/07/31 12:05:02 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef IMAGE_H
#define IMAGE_H

typedef struct s_window t_window;

typedef struct s_image
{
	void	*img_ptr;
    char	*addr;
    int		bpp; /* bits per pixel */
    int		line_len;
    int		endian;
}   t_image;

void    create_image(t_window *window, t_image *image);
void    put_image_to_window(t_window *window, t_image *image);

#endif