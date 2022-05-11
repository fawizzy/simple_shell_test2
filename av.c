#include <stdio.h>

/**
 * a program that print all argument without ac
 * @av: null terminated array of strings
 * @ac: number of items in av
 * Return: 0
 */

int main(__attribute__ ((unused)) int ac, char **av)
{
	int i = 1;

	while (av[i])
	{
		printf("%s ", av[i]);
		i++;
	}
	printf("\n");
	return (0);
}
