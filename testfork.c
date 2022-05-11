#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
	int id;
	int status;
	char *argv[] = {"/bin/ls", NULL};

	id = fork();

	if (id == 0)
	{
		printf("this is the first child\n");
		if (execve(argv[0], argv, NULL) == -1)
			perror("Error:");
		fflush(stdout);
		sleep(3);
	}
	else
	{
		wait(&status);
		id = fork();
		if (id == 0)
		{
			printf("this is the second child\n");
			if (execve(argv[0], argv, NULL) == -1)
				perror("Error:");
			fflush(stdout);
			sleep(3);
		}
		else
		{
			wait(&status);
			id = fork();

			if (id == 0)
			{
				printf("this is the third child\n");
				if (execve(argv[0], argv, NULL))
					perror("Error:");
				fflush(stdout);
				sleep(3);
			}
			else
			{
				wait(&status);
				id = fork();

				if (id == 0)
				{
					printf("this is the fourth child\n");
					if (execve(argv[0], argv, NULL))
						perror("Error:");
					fflush(stdout);
					sleep(3);
				}
				else
				{
					wait(&status);
					id = fork();

					if (id == 0)
					{
						printf("this is the fifth child\n");
						if (execve(argv[0], argv, NULL))
							perror("Error:");
					}
					else
						return (0);
				}
			}
		}
	}

	return (0);
}
