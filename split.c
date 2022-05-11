#include <stdio.h>
#include <string.h>

/**
 * splits a string and return an array of each world
 */

int main(__attribute__((__unused__)) int argc, char *argv[])
{
	char *piece = strtok(argv[1], "/");
	while (piece)
	{
		printf("%s\n ", piece);
		piece = strtok(NULL, "/");
	}

	return (0);
}
