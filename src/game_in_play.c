/*
** EPITECH PROJECT, 2018
** PSU_morpion_2018
** File description:
** game_in_play.c
*/

#include "../include/morpion.h"

void send_signal(char **map, char camp)
{
    char *attack;

    attack = get_attack();
    for (int i = 0; i < 2; i++) {
        for (int cols = (attack[i] - 48); cols > 0; cols--) {
            kill(morpion, SIGUSR1);
            usleep(2000);
        }
        kill(morpion, SIGUSR2);
        usleep(2000);
    }
    change_map(map, attack[0] - 48, attack[1] - 48, camp);
}

char *receive_signal(char **map, char camp)
{
    int i = 0;
    int y = 0;

    write(1, "waiting for enemy's attack...\n", 30);
    pause();
    while (morpion == 10) {
        y++;
        pause();
    }
    pause();
    while (morpion == 10) {
        i++;
        pause();
    }
    change_map(map, y, i, camp);
}

int player_one_in_game(char **map)
{
    char *signal_enemy;
    int ending = check_if_end(map);

    while (ending >= 0) {
        display_map(map);
        send_signal(map, 'x');
        ending = check_if_end(map);
        if (ending < 0)
            return (ending);
        display_map(map);
        signal_enemy = receive_signal(map, 'o');
        ending = check_if_end(map);
        if (ending < 0)
            return (ending);
    }
    display_map(map);
    return (ending);
}

int player_two_in_game(char **map)
{
    char *signal_enemy;
    int ending = check_if_end(map);

    while (ending >= 0) {
        display_map(map);
        signal_enemy = receive_signal(map, 'x');
        ending = check_if_end(map);
        if (ending < 0)
            return (ending);
        display_map(map);
        send_signal(map, 'o');
        ending = check_if_end(map);
        if (ending < 0)
            return (ending);
    }
    display_map(map);
    return (ending);
}