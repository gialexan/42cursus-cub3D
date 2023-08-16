/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extension.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 12:12:48 by gialexan          #+#    #+#             */
/*   Updated: 2023/08/16 16:34:36 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_bool	check_extension(const char *pathname, const char *extension)
{
	const char	*file_ext;

	file_ext = ft_strrchr(pathname, '.');
	if (file_ext)
	{
		file_ext++;
		if (ft_strncmp(file_ext, extension, ft_strlen(extension) + 1) == 0)
			return (TRUE);
	}
	return (FALSE);
}
