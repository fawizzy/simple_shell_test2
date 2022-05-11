#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 *  * main - fork & wait example
 *   *
 *    * Return: Always 0.
 *     */
int main(void)
{
	int status;
	int id =  fork();
	int n;

	if (id == 0)
		n = 1;
	else
		n = 6;

	int i;

	if (id == 0)
		wait(&status);

	for (i = n; i < n + 5; i++)
	{
		printf("%d ", i);
		fflush(stdout);
	}

	printf("\n");
	return (0);
}
