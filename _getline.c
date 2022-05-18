#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include <fcntl.h>
#include "main.h"
/**
 * _getline - get the line
 *
 * Return: Always 0.
 */
char *_getline(void)
{
	size_t size = 0;
	char *line = NULL;
	ssize_t read;

	printf("$ ");
	read = getline(&line, &size, stdin);
	if (read < 0)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
