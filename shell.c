#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include "main.h"
#include <stdlib.h>
/**
 * shell - super simple shell
 *
 * Return: Always 0.
 */
int shell(void)
{
	pid_t child_pid;
	int status, retour, i = 0;
	char *line, *value;
	char **argv = (char **) malloc(sizeof(char **));

	if (argv == NULL)
	{
		return (0);
	}
	while ((line = _getline()) != NULL)
	{
		line = strtok(line, "\n");
		line = line + '\0';
		while ((value = strtok(NULL, " ")) != NULL)
		{
			*(argv + i) = value;
			printf("%s", value);
			i++;
		}
		*(argv + i) = NULL;
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error:");
			return (1);
		}
		if (child_pid == 0)
		{
			retour = execve(argv[0], argv, NULL);
			if (retour == -1)
			{
				perror("./hsh");
			}
		}
		else
		{
			wait(&status);
		}
	}
	return (0);
}
