/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 16:29:31 by gialexan          #+#    #+#             */
/*   Updated: 2023/08/10 16:30:24 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_bool is_valid_floor(char **map_dup, int row, int col)
{
    char cell;

    cell = map_dup[row][col];
    if (cell == ' ' || cell == '\0')
        return (FALSE);
    if (cell == '1' || cell == '@' || cell == '!')
        return FALSE;
    return TRUE;
}

void    check_upper_right(char **map_dup, int row, int col)
{
    char cell;

    cell = map_dup[row - 1][col + 1];
    if (cell == '1')
        map_dup[row - 1][col + 1] = '!';
    else if (cell == ' ' || cell == '\0')
        map_dup[row][col] = '#';
}

void    check_upper_left(char **map_dup, int row, int col)
{
    char cell;

    cell = map_dup[row - 1][col - 1];
    if (cell == '1')
        map_dup[row - 1][col - 1] = '!';
    else if (cell == ' ' || cell == '\0')
        map_dup[row][col] = '#';
}

void    check_lower_right(char **map_dup, int row, int col)
{
    char cell;

    cell = map_dup[row + 1][col + 1];
    if (cell == '1')
        map_dup[row + 1][col + 1] = '!';
    else if (cell == ' ' || cell == '\0')
        map_dup[row][col] = '#';
}

void    check_lower_left(char **map_dup, int row, int col)
{
    char cell;

    cell = map_dup[row + 1][col - 1];
    if (cell == '1')
        map_dup[row + 1][col -1] = '!';
    else if (cell == ' ' || cell == '\0')
        map_dup[row][col] = '#';
}


void flood_fill(char **map_dup, int row, int col)
{
    if (is_valid_floor(map_dup, row, col))
    {
        map_dup[row][col] = '@';
        check_upper_left(map_dup, row, col);
        check_upper_right(map_dup, row, col);
        check_lower_right(map_dup, row, col);
        check_lower_left(map_dup, row, col);
        flood_fill(map_dup, row, col + 1);
        flood_fill(map_dup, row, col - 1);
        flood_fill(map_dup, row + 1, col);
        flood_fill(map_dup, row - 1, col);
    }
    return ;
}
