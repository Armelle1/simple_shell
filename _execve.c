#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>
#include "main.h"
/**
 * _execve - execute programm
 * @arg: 1st parameter
 *@argv: 2nd parameter
 *@envp: 3rd parameter
 * Return: (void).
 */
void _execve(char **arg, char **argv, char **envp)
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
		retour = execve(argv[0], argv, envp);
		if (retour == -1)
		{
			perror(arg[0]);
		}
	}
	else
	{
		wait(&status);
	}
}
