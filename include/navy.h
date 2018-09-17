/*
** EPITECH PROJECT, 2018
** navy
** File description:
** headers of navy
*/

#ifndef NAVY_H_
#define NAVY_H_

#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>

typedef struct map_s {
	char *map;
	char *map_vs;
	char *enemy;
} board_t;

int usage(void);
void handler(int);
void trunc_and_write(char *, char *);
char *create_map(char *);
int find_start(int, char *);
char *add_one_ship(char *, char *);
char *add_ships(char *, char *);
char *recup_action(char *);
char *hited(board_t *, char *);
char *hit(board_t *, char *);
void verif_win(board_t *, int *);
int game(board_t *, int, int);
int player1(int);
int player2(int, char *);
int turn1(board_t *, int, int *);
int turn2(board_t *, int, int *);
void trunc_and_write(char *, char *);
void disp_maps(char *, char *);

#endif
