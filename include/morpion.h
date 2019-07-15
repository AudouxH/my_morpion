/*
** EPITECH PROJECT, 2018
** PSU_morpion_2018
** File description:
** morpion.h
*/

#ifndef MORPION_H
#define MORPION_H
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

//signal.c
void write_info(char *info);
void get_pid(int sig, siginfo_t *info, void *ucontext);
void counter(int sig, siginfo_t *info, void *ucontext);
void def_sig(void);

//my_lib.c
int my_getnbr(char const *str);
void my_put_nbr(int nb);
int my_strlen(char *str);

//my_lib2.c
void my_putchar(char c);

//make_map.c
char **create_map(void);
void display_map(char **map);

//game_in_play.c
void send_signal(char **map, char camp);
char *receive_signal(char **map, char camp);
int player_one_in_game(char **map);
int player_two_in_game(char **map);

//get_next_line.c
int check_n(char const *str);
char *str_cat(char *filepath, char *filepath_2);
char *get_next_line(int fd);

//attack.c
int check_attack(char *attack);
char *get_attack(void);

//game_in_play2.c
void change_map(char **map, int i, int y, char player);
void change_map_enemy(char **map, int i, int y, char player);
int check_if_end(char **map);

//ending_game.c
int check_line_end(char **map);
int check_diago_end(char **map);
int check_all_end(char **map);

volatile int morpion;
#endif