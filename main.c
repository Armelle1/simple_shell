#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "main.h"

/**
 * main - test functions
 *@argc: 1st param
 *@argv: 2nd param
 *@envp: 3rd param
 * Return: Always 0.
 */
int main(int argc, char *argv[], char *envp[])
{
	if (argc < 1 || argv == NULL)
	{
		return (0);
	}
	shell(envp);
	return (0);
}
