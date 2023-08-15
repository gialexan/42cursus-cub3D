/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 14:25:59 by gialexan          #+#    #+#             */
/*   Updated: 2023/08/15 11:26:29 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_bool is_invalid_line(char *line);
static t_bool open_texture_file(char *pathname);
static t_bool is_unexpected(char *line, char *expected);

void    parser_texture(t_cub3d *cub3d, t_texture *texture, char *expected)
{
	char	line[BUFFER];
	char	*read_line;
	char	*clean_line;

	ft_memset(line, NULL_CHAR, BUFFER);
	read_line = gnl(cub3d->fd);
	if (!read_line)
		cub3d_error(cub3d, FILE_EMPTY_ERROR, FILE_EMPTY_MSG);
	clean_line = ft_strtrim(read_line, STRING_LINE_BREAK);
	ft_strlcpy(line, clean_line, BUFFER);
	free(read_line);
	free(clean_line);
	if (is_invalid_line(line))
		cub3d_error(cub3d, FILE_SETTING_ERROR, FILE_SETTING_MSG);
	else if (is_unexpected(line, expected))
        cub3d_error(cub3d, PARSER_TEXTURE_ERROR, PARSER_TEXTURE_MSG);
	else if (!check_extension(line, TEXTURE_EXTENSION))
		cub3d_error(cub3d, TEXTURE_EXTENSION_ERROR, TEXTURE_EXTENSION_MSG);
	else if (!open_texture_file(line + PATHNAME_START_INDEX))
		cub3d_error(cub3d, TEXTURE_FILE_ERROR, TEXTURE_FILE_MSG);
	ft_strlcpy(texture->pathname, line + PATHNAME_START_INDEX, BUFFER);
}

static t_bool	open_texture_file(char *pathname)
{
	int fd;

	fd = open(pathname, O_RDONLY);
	if (fd == -1)
		return (FALSE);
	close(fd);
	return (TRUE);
}

static t_bool is_unexpected(char *line, char *expected)
{
    return (line[0] != expected[0]
        || line[1] != expected[1]
		|| line[2] != WHITE_SPACE);
}

static t_bool is_invalid_line(char *line)
{
    return (line[0] == CHAR_LINE_BREAK
        || ft_isspace(line[0]) 
        || line[0] == NULL_CHAR);
}