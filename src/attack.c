/*
** EPITECH PROJECT, 2018
** PSU_morpion_2018
** File description:
** attack.c
*/

#include "../include/morpion.h"

int check_attack(char *attack)
{
    if ((attack[0] - 48) < 1 || (attack[0] - 48) > 3) {
        write(1, "wrong position\n", 15);
        return (-1);
    }
    return (0);
}

char *get_attack(void)
{
    char *line;
    char *cols;
    char *attack;

    do {
    write(1, "line: ", 6);
    line = get_next_line(0);
    } while (check_attack(line) == -1);
    do {
    write(1, "colone: ", 8);
    cols = get_next_line(0);
    } while (check_attack(cols) == -1);
    attack = str_cat(line, cols);
    return (attack);
}