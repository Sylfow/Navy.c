/*
** EPITECH PROJECT, 2018
** my_atoi
** File description:
** str to int
*/

int my_atoi(char *str)
{
	int i = 0;
	int nbr = 0;

	while (str[i] != '\0') {
		if (str[i] >= '0' && str[i] <= '9') {
			nbr = nbr * 10;
			nbr = nbr + str[i] - '0';
		} else
			return (nbr);
		i = i + 1;
	}
	return (nbr);
}
