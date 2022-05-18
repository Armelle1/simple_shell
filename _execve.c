#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>
#include "main.h"
/**
 * _execve - execute programm
 *@argv: parameter
 * Return: (void).
 */
void _execve(char **argv)
{
	pid_t child_pid;
	int status, retour;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:");
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
