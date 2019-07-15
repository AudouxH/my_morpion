/*
** EPITECH PROJECT, 2018
** PSU_morpion_2018
** File description:
** game_in_play2.c
*/

#include "../include/morpion.h"

void change_map(char **map, int i, int y, char player)
{
    if (map[i - 1][y - 1] == '.')
        map[i - 1][y - 1] = player;
}

void change_map_enemy(char **map, int i, int y, char player)
{
    if (map[i - 1][y - 1] == '.')
        map[i - 1][y - 1] = player;
}

int check_if_end(char **map)
{
    if (check_line_end(map) == -1 || check_line_end(map) == -2)
        return (check_line_end(map));
    else if (check_diago_end(map) == -1 || check_diago_end(map) == -2)
        return (check_diago_end(map));
    else if (check_all_end(map) == -1)
        return (-3);
    return (0);
}