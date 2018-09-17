/*
** EPITECH PROJECT, 2018
** map.c
** File description:
** creat all maps
*/

#include "navy.h"
#include "my.h"

void trunc_and_write(char *fname, char *str)
{
	int fd = open(fname, O_WRONLY | O_TRUNC);

	write(fd, str, my_strlen(str));
	fd = close(fd);
}

char *create_map(char *map)
{
	int fd = open("maps/map", O_RDONLY);

	read(fd, map, 180);
	fd = close(fd);
	return (map);
}

int find_start(int start, char *line)
{
	switch (line[2]) {
	case 'A':
		start = 2;
		break;
	case 'B':
		start = 4;
		break;
	case 'C':
		start = 6;
		break;
	case 'D':
		start = 8;
		break;
	case 'E':
		start = 10;
		break;
	case 'F':
		start = 12;
		break;
	case 'G':
		start = 14;
		break;
	case 'H':
		start = 16;
		break;
	}
	return (start);
}

char *add_one_ship(char *map, char *line)
{
	int start = 0;
	int which_line = line[3] - '0' + 2;
	int count = line[0] - '0';
	int i;

	start = find_start(start, line);
	start = (which_line - 1) * 18 + start;
	if (line[2] == line[5]) {
		for (i = 1; i <= count; i++) {
			map[start] = line[0];
			start = start + 18;
		}
	} else if (line[3] == line[6]) {
		for (i = 1; i <= count; i++) {
			map[start] = line[0];
			start = start + 2;
		}
	}
	return (map);
}

char *add_ships(char *map, char *path_to_file)
{
	int fd = open(path_to_file, O_RDONLY);
	char *line = malloc(sizeof(char) * 8);
	int i = 0;

	while (i < 4) {
		read(fd, line, 8);
		map = add_one_ship(map, line);
		i = i + 1;
	}
	close(fd);
	return (map);
}
