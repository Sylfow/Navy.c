/*
** EPITECH PROJECT, 2018
** my_put_nbr
** File description:
** put nmb
*/

#include "my.h"

int my_put_nbr(int nb)
{
	if (nb < 0) {
		nb = -nb;
		my_putchar('-');
	}
	if (nb > 9) {
		my_put_nbr(nb / 10);
		my_put_nbr(nb % 10);
	} else
		my_putchar(nb + 48);
	return (0);
}
