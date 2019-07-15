/*
** EPITECH PROJECT, 2018
** PSU_morpion_2018
** File description:
** make_map.c
*/

#include "../include/morpion.h"

char **create_map(void)
{
    char **map = malloc(sizeof(char *) * 3);

    for (int i = 0; i < 3; i++) {
        map[i] = malloc(sizeof(char) * 3);
        for (int y = 0; y < 8; y++)
            map[i][y] = '.';
    }
    return (map);
}

void display_map(char **map)
{
    write(1, "\n   | 1 | 2 | 3 |\n ", 19);
    for (int i = 0; i < 3; i++) {
        write(1, "- + - + - + - +\n ", 17),
        my_put_nbr(i + 1);
        for (int y = 0; y < 3; y++) {
            write(1, " | ", 3);
            write(1, &map[i][y], 1);
        }
        write(1, " |\n ", 4);
    }
    write(1, "- + - + - + - +\n\n", 17);
}