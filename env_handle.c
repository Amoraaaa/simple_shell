#include "main.h"

/**
 * setenv_builtin - setenv built-in
 *
 * @args: command arguments
 *
 * Return: 0 (success), -1 (failure)
 */
int setenv_builtin(char *args[])
{
	if (args[1] == NULL || args[2] == NULL)
	{
		return (-1);
	}

	if (setenv(args[1], args[2], 1) != 0)
	{
		perror("setenv");
		return (-1);
	}

	return (0);
}

/**
 * unsetenv_builtin - unsetenv built-in command
 *
 * @args: array of command arguments
 *
 * Return: 0 (success), -1 (failure)
 */
int unsetenv_builtin(char *args[])
{
	if (args[1] == NULL)
	{
		return (-1);
	}

	if (unsetenv(args[1]) != 0)
	{
		perror("unsetenv");
		return (-1);
	}

	return (0);
}
