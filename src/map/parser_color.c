/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 14:37:00 by gialexan          #+#    #+#             */
/*   Updated: 2023/08/14 21:21:14 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int      extract_rgb(char *line);
static t_bool   is_invalid_line(char *line);
static t_bool   is_unexpected(char *line, char *expected);

void	parser_color(t_cub3d *cub3d, t_rgb *color, char *expected)
{
	char	line[BUFFER];
	char	*read_line;
	char	*clean_line;

	ft_memset(line, NULL_CHAR, BUFFER);
	read_line = gnl(cub3d->fd);
	clean_line = ft_strtrim(read_line, STRING_LINE_BREAK);
	ft_strlcpy(line, clean_line, BUFFER);
	free(read_line);
	free(clean_line);
	if (is_invalid_line(line))
		cub3d_error(cub3d, FILE_SETTING_ERROR, FILE_SETTING_MSG);
	if (is_unexpected(line, expected))
		cub3d_error(cub3d, PARSER_COLOR_ERROR, PARSER_COLOR_MSG);
	color->r = extract_rgb(line + COLOR_START_INDEX);
	color->g = extract_rgb(line + COLOR_START_INDEX);
	color->b = extract_rgb(line + COLOR_START_INDEX);
	if (color->r == -1 || color->g == -1|| color->b == -1)
		cub3d_error(cub3d, PARSER_COLOR_ERROR, PARSER_COLOR_MSG);
}

static int	extract_rgb(char *line)
{
    static int i = 0;
    static int calls = 0;
    int rgb;

	if (!*(line + i))
		return (-1);
	rgb = ft_atoi(line + i);
    while (line[i] && line[i] != ',')
	{
		if (!ft_isdigit(line[i]))
			return (-1);
		i++;
	}
    if (line[i] == ',')
        i++;
    if (calls == 2)
        i = 0;
    calls++;
    return (rgb);
}

static t_bool is_unexpected(char *line, char *expected)
{
    return (line[0] != expected[0] || line[1] != WHITE_SPACE);
}

static t_bool is_invalid_line(char *line)
{
    return (line[0] == CHAR_LINE_BREAK
        || ft_isspace(line[0])
        || line[0] == NULL_CHAR);
}
