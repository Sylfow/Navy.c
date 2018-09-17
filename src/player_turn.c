/*
** EPITECH PROJECT, 2018
** turn game
** File description:
** turn of the game
*/

#include "navy.h"
#include "my.h"

void errno(board_t *maps, char *line, int *ok)
{
	if (my_strlen(line) != 2)
		my_putstr("wrong position\n");
	else if (line[0] > 'H' || line[0] < 'A'
		 || line[1] > '8' || line[1] < '1')
		my_putstr("wrong position\n");
	else {
		trunc_and_write("pid", line);
		*ok = 1;
		my_putstr(line);
		my_putstr(hit(maps, line));
	}
}

int turn2(board_t *maps, int pid, int *win)
{
	char *line;
	int ok = 0;

	signal(SIGUSR2, handler);
	my_putstr("waiting for enemy's attack...\n");
	pause();
	usleep(10000);
	line = recup_action("pid");
	if (line[0] == 'I')
		return (0);
	my_putstr(line);
	my_putstr(hited(maps, line));
	my_putchar('\n');
	while (ok == 0) {
		my_putstr("attack: ");
		if ((line = get_next_line(0)) == NULL) {
			*win = 0;
			trunc_and_write("pid", "I9");
			kill(pid, SIGUSR1);
			free(line);
			return (0);
		}
		if (line[0] == '\n') {
			free(line);
			continue;
		}
		errno(maps, line, &ok);
		free(line);
	}
	kill(pid, SIGUSR1);
	disp_maps(maps->map, maps->map_vs);
	verif_win(maps, win);
	return (1);
}

int turn1(board_t *maps, int pid, int *win)
{
	char *line;
	int ok = 0;

	signal(SIGUSR1, handler);
	while (ok == 0) {
		my_putstr("attack: ");
		if ((line = get_next_line(0)) == NULL) {
			*win = 0;
			trunc_and_write("pid", "I9");
			kill(pid, SIGUSR2);
			free(line);
			return (0);
		}
		if (line[0] == '\n') {
			free(line);
			continue;
		}
		errno(maps, line, &ok);
		free(line);
	}
	kill(pid, SIGUSR2);
	my_putstr("\nwaiting for enemy's attack...\n");
	pause();
	usleep(10000);
	line = recup_action("pid");
	if (line[0] == 'I')
		return (0);
	my_putstr(line);
	my_putstr(hited(maps, line));
	disp_maps(maps->map, maps->map_vs);
	verif_win(maps, win);
	return (1);
}
