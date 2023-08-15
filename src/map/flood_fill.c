/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gialexan <gialexan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 16:29:31 by gialexan          #+#    #+#             */
/*   Updated: 2023/08/14 21:35:33 by gialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_bool is_valid_floor(char **map, int row, int col)
{
    char cell;

    cell = map[row][col];
    if (cell == ' ' || cell == '\0')
        return (FALSE);
    if (cell == '1' || cell == '@' || cell == '!')
        return (FALSE);
    return TRUE;
}

void    check_upper_right(char **map, int row, int col)
{
    char cell;

    cell = map[row - 1][col + 1];
    if (cell == '1')
        map[row - 1][col + 1] = '!';
    else if (cell == ' ' || cell == '\0')
        map[row][col] = '0';
}

void    check_upper_left(char **map, int row, int col)
{
    char cell;

    cell = map[row - 1][col - 1];
    if (cell == '1')
        map[row - 1][col - 1] = '!';
    else if (cell == ' ' || cell == '\0')
        map[row][col] = '0';    
}

void    check_lower_right(char **map, int row, int col)
{
    char cell;

    cell = map[row + 1][col + 1];
    if (cell == '1')
        map[row + 1][col + 1] = '!';
    else if (cell == ' ' || cell == '\0')
        map[row][col] = '0';
}

void    check_lower_left(char **map, int row, int col)
{
    char cell;

    cell = map[row + 1][col - 1];
    if (cell == '1')
        map[row + 1][col -1] = '!';
    else if (cell == ' ' || cell == '\0')
        map[row][col] = '0';
}

//ANOTAÇÃO: NO FINAL SE SOBRAR CARACTER 0 PELO MEIO DO MAPA É INDICAÇÃO DE UM ERRO.
// void flood_fill(char **map, int row, int col)
// {
//     if (is_valid_floor(map, row, col))
//     {
//         map[row][col] = '@';
//         check_upper_left(map, row, col);
//         check_upper_right(map, row, col);
//         check_lower_right(map, row, col);
//         check_lower_left(map, row, col);
//         flood_fill(map, row, col + 1);
//         flood_fill(map, row, col - 1);
//         flood_fill(map, row + 1, col);
//         flood_fill(map, row - 1, col);
//     }
//     return ;
// }




#include <stdlib.h>
void flood_fill(char **map, int row, int col)
{
    if (is_valid_floor(map, row, col))
    {
        map[row][col] = '@';
        check_upper_left(map, row, col);
        check_upper_right(map, row, col);
        check_lower_right(map, row, col);
        check_lower_left(map, row, col);
        for (int i = 0; map[i]; i++)
	    {
            for (int j = 0; map[i][j]; j++)
            {
                if (map[i][j] == '@')
                    ft_printf("%s%c%s", "\033[32m", map[i][j], "\x1b[0;30m");
                else if (map[i][j] == '!')
                    ft_printf("%s%c%s", "\033[31m", map[i][j], "\x1b[0;30m");
                else
                    ft_printf("%s%c%s", "\033[31m", map[i][j], "\x1b[0;30m");
                usleep(5);
            }
            printf("\n");
	    }
        (void)!system("clear");
        flood_fill(map, row, col + 1);
        flood_fill(map, row, col - 1);
        flood_fill(map, row + 1, col);
        flood_fill(map, row - 1, col);
    }
    return ;
}