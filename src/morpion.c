/*
** EPITECH PROJECT, 2018
** PSU_morpion_2018
** File description:
** morpion.c
*/

#include "../include/morpion.h"

int player_one(char **av)
{
    char **map = create_map();
    int winner = 0;

    write_info("\nwaiting for enemy connection...\n");
    pause();
    write(1, "\nenemy connected\n", 17);
    winner = player_one_in_game(map);
    if (winner == -1) {
        display_map(map);
        write(1, "\nYou lost ...\n", 14);
        return (2);
    }
    else if (winner == -2) {
        display_map(map);
        write(1, "\nYou win ...\n", 13);
        return (1);
    }
}

int player_two(char **av)
{
    char **map = create_map();
    int winner = 0;

    write_info("\n");
    kill(my_getnbr(av[1]), SIGUSR2);
    usleep(2000);
    write(1, "successfully connected\n", 23);
    winner = player_two_in_game(map);
    if (winner == -1) {
        write(1, "\nYou win ...\n", 13);
        return (1);
    }
    else if (winner == -2) {
        write(1, "\nYou lost ...\n", 14);
        return (2);
    }
}

int main(int ac, char **av)
{
    def_sig();
    if (ac != 1 && ac != 2)
        return (84);
    if (ac == 1)
        return (player_one(av));
    else if (ac == 2)
        return (player_two(av));
}