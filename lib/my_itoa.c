/*
** EPITECH PROJECT, 2018
** my_itoa
** File description:
** convert int to char*
*/

#include "my.h"

char *my_itoa(int nb)
{
	int len = 0;
	char *str;
	int tmp = nb;

	while (tmp > 0) {
		tmp /= 10;
		len++;
	}
	str = malloc(sizeof(*str) * (len + 1));
	str[len] = '\0';
	while (len--) {
		str[len] = nb % 10  + '0';
		nb /= 10;
	}
	return (str);
}
