/*
** EPITECH PROJECT, 2018
** game
** File description:
** play
*/

#include <navy.h>
#include <my.h>

void handler(int sig)
{
	if (sig == SIGUSR1 || sig == SIGUSR2) {
	}
}

void disp_maps(char *map, char *map_vs)
{
	my_putstr("\nmy positions:\n");
	my_putstr(map);
	my_putstr("\n");
	my_putstr("enemy's positions:\n");
	my_putstr(map_vs);
	my_putstr("\n");
}

int player1(int pid)
{
	char pid_str[10];
	int fd;

	signal(SIGUSR2, handler);
	my_putstr("my_pid: ");
	my_put_nbr(pid);
	my_putstr("\nwaiting for enemy connection...\n");
	pause();
	fd = open("pid", O_RDONLY);
	read(fd, pid_str, 10);
	fd = close(fd);
	my_putstr("\nenemy connected\n");
	return (my_atoi(pid_str));
}

int player2(int pid, char *j1_pid)
{
	signal(SIGUSR1, handler);
	trunc_and_write("pid", my_itoa(pid));
	my_putstr("my_pid: ");
	my_put_nbr(pid);
	my_putchar('\n');
	kill(my_atoi(j1_pid), SIGUSR2);
	my_putstr("successfully connected\n");
	return (my_atoi(j1_pid));
}

char *recup_enemy(char *path, char *map)
{
	int fd = open(path, O_RDONLY);

	read(fd, map, 180);
	close(fd);
	return (map);
}

int game(board_t *maps, int ac, int pid)
{
	int win = -1;

	if (ac == 2)
		maps->enemy = recup_enemy("maps/map2", maps->enemy);
	if (ac == 3)
		maps->enemy = recup_enemy("maps/map1", maps->enemy);
	disp_maps(maps->map, maps->map_vs);
	while (win == -1) {
		if (ac == 2) {
			if (turn1(maps, pid, &win) == 0)
				win = 0;
		}
		if (ac == 3) {
			if (turn2(maps, pid, &win) == 0)
				win = 0;
		}
	}
	return (win);
}
