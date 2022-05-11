#include <stdio.h>
#include <stdlib.h>

/**
 * a program that prints $ and wait for the user to enter 
 *		  a command and print it on the next line
 *
 * @ac: number of argument
 * @av: array of strings
 *
 * Return: 0
 */

int main()
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;

	printf("$ ");


	while ((nread = getline(&line, &len, stdin)))
	{
		printf("%s\n", line);
	}

	if (nread == -1)
		printf("error");	

	free(line);
	exit(EXIT_SUCCESS);

}
