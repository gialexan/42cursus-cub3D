/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 12:03:22 by gialexan          #+#    #+#             */
/*   Updated: 2023/07/12 15:21:26 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CUB3D_H
#define CUB3D_H

#include <libft.h>
#include <stdio.h>
#include <mlx.h>
#include <time.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


//KEY EVENTS
//Bottons
# define KEY_ESC            0xff1b
# define KEY_LEFT_ARROW     0xff51
# define KEY_UP_ARROW       0xff52  
# define KEY_RIGHT_ARROW    0xff53
# define KEY_DOWN_ARROW     0xff54
# define KEY_A              0x0061
# define KEY_S              0x0073
# define KEY_D              0x0064
# define KEY_W              0x0077


//MASK EVENTS
# define KEY_PRESS        2
# define KEY_RELEASE      3
# define DESTROY_NOTIFY   17

# define NO_EVENT_MASK 0L
# define KEY_PRESS_MASK 1L << 0
# define KEY_RELEASE_MASK 1L << 1

#endif