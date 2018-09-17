/*
** EPITECH PROJECT, 2018
** main
** File description:
** main of navy
*/

#include "navy.h"
#include "my.h"
#include <stdio.h>

int usage(void)
{
	my_putstr("USAGE\n     ./navy [first_player_pid] navy_positions\n");
	my_putstr("DESCRIPTION\n     first_player_pid:  only for the");
	my_putstr(" 2nd player.  pid of the first player.\n     ");
	my_putstr("navy_positions:  file representing the positions");
	my_putstr(" of the ships.\n");
	return (0);
}

int mendatory(board_t *maps, int ac, char **av)
{
	maps->map = malloc(sizeof(char) * 181);
        maps->map_vs = malloc(sizeof(char) * 181);
        maps->enemy = malloc(sizeof(char) * 181);
        if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0') {
                usage();
                return (0);
        }
        maps->map = create_map(maps->map);
        maps->map_vs = create_map(maps->map_vs);
	return (1);
}

int main(int ac, char **av)
{
	board_t maps;
	int pid = getpid();

	if (ac == 1 || ac > 3)
		return (84);
	if (mendatory(&maps, ac, av) == 0)
		return (0);
	if (ac == 2) {
		maps.map = add_ships(maps.map, av[1]);
		trunc_and_write("maps/map1", maps.map);
		pid = player1(pid);
	}
	else if (ac == 3) {
		maps.map = add_ships(maps.map, av[2]);
		trunc_and_write("maps/map2", maps.map);
		pid = player2(pid, av[1]);
	}
	return (game(&maps, ac, pid));
}
