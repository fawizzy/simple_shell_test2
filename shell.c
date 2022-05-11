#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	char *token;
	char *piece[10] = {NULL};
	char *delimiter = " \n\t\r\v\f";
	int status;

	char *argv[]= {NULL, NULL};

	while ((nread = getline(&line, &len, stdin)))
	{
		printf("fawizzy_shell>>>");
		argv[0] = line;
		token = strtok(line, delimiter);
		int i = 0;
		while (token != NULL)
		{
			piece[i++] = token;
			//printf("%s ", token);
			token = strtok(NULL, delimiter);			
		}

		int id = fork();

		if (id == 0)
		{
			if (execve(piece[0], argv, NULL) == -1)
				perror("Error:");
		}
		else
			wait(&status);
	}
	free(line);
	exit(EXIT_SUCCESS);
}
