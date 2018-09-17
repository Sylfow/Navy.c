/*
** EPITECH PROJECT, 2018
** win_conditio.c
** File description:
** win condition for navy game
*/

#include "navy.h"
#include "my.h"

char *recup_action(char *file)
{
	char *line;
	int fd = open(file, O_RDONLY);

	line = get_next_line(fd);
	close(fd);
	return (line);
}

char *hited(board_t *maps, char *line)
{
	int c = 0;
	char y = '1';

	while (maps->map[c] != line[0])
		c = c + 1;
	c = c + 36;
	while (y != line[1]) {
		y = y + 1;
		c = c + 18;
	}
	if (maps->map[c] == '.' || maps->map[c] == 'o') {
		maps->map[c] = 'o';
		return (": missed\n");
	} else {
		maps->map[c] = 'x';
		return (": hit\n");
	}
}

char *hit(board_t *maps, char *line)
{
	int c = 0;
	char y = '1';

	while (maps->enemy[c] != line[0])
		c = c + 1;
	c = c + 36;
	while (y != line[1]) {
		y = y + 1;
		c = c + 18;
	}
	if (maps->enemy[c] == '.') {
		maps->map_vs[c] = 'o';
		return (": missed\n");
	} else {
		maps->map_vs[c] = 'x';
		return (": hit\n");
	}
}

void verif_win(board_t *maps, int *win)
{
	int w = 14;
	int l = 14;

	for (int i = 0; maps->map[i] != '\0'; i++) {
		if (maps->map[i] == 'x')
			l = l - 1;
	}
	for (int i = 0; maps->map_vs[i] != '\0'; i++) {
		if (maps->map_vs[i] == 'x')
			w = w - 1;
	}
	if (w == 0 && l != 0) {
		*win = 0;
		my_putstr("I won\n");
	}
	if (w != 0 && l == 0) {
		*win = 1;
		my_putstr("Enemy won\n");
	}
}
