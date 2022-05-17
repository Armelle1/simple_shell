#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include "main.h"

/**
 * shell - super simple shell
 *
 * Return: Always 0.
 */
int shell(void)
{
	pid_t child_pid;
	int status, retour;
	char *line;
	char *argv[] = {NULL, NULL};

	while ((line = _getline()) != NULL)
	{
		line = strtok(line, "\n");
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error:");
			return (1);
		}
		if (child_pid == 0)
		{
			argv[0] = line + '\0';
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
