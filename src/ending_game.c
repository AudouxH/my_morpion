/*
** EPITECH PROJECT, 2018
** PSU_morpion_2018
** File description:
** ending_game.c
*/

#include "../include/morpion.h"

int check_line_end(char **map)
{
    for (int i = 0; i < 3; i++)
        if (map[i][0] == 'o' && map[i][1] == 'o' && map[i][2] == 'o')
            return (-1);
    for (int i = 0; i < 3; i++)
        if (map[i][0] == 'x' && map[i][1] == 'x' && map[i][2] == 'x')
            return (-2);
    for (int i = 0; i < 3; i++)
        if (map[0][i] == 'o' && map[1][i] == 'o' && map[2][i] == 'o')
            return (-2);
    for (int i = 0; i < 3; i++)
        if (map[0][i] == 'o' && map[1][i] == 'o' && map[2][i] == 'o')
            return (-2);
    return (0);
}

int check_diago_end(char **map)
{
    if (map[0][0] == 'o' && map[1][1] == 'o' && map[2][2] == 'o')
        return (-1);
    else if (map[0][0] == 'x' && map[1][1] == 'x' && map[2][2] == 'x')
        return (-2);
    if (map[0][2] == 'o' && map[1][1] == 'o' && map[2][0] == 'o')
        return (-1);
    if (map[0][2] == 'x' && map[1][1] == 'x' && map[2][0] == 'x')
        return (-2);
    return (0);
}

int check_all_end(char **map)
{
    for (int i = 0; i < 3; i++)
        for (int y = 0; y < 3; y++)
            if (map[i][y] == '.')
                return (0);
    return (-1);
}
