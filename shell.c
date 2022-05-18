#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include "main.h"
#include <stdlib.h>
/**
 * shell - super simple shell
 * @arg: 1st parameter
 *@envp : 2nd parameter
 * Return: Always 0.
 */
int shell(char ** arg, char **envp)
{
	int i;
	char *line, *value, *res;
	char **argv = (char **) malloc(sizeof(char *) * 50);

	if (argv == NULL)
	{
		return (0);
	}
	while ((line = _getline()) != NULL)
	{
		i = 0;
		line = line + '\0';
		res = strtok(line, "\n");
		value = strtok(res, " ");
		while (value != NULL)
		{
			*(argv + i) = value;
			value = strtok(NULL, " ");
			i++;
		}
		*(argv + i) = NULL;
		_execve(arg, argv, envp);
	}
	return (0);
}
