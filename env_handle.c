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

/**
 * builtin_commands_handling - handle built-in commands
 * @args: array of arguments
 * @env_path: environment's path
 * Return: exec number
 */

int builtin_commands_handling(char *args[], char *env_path)
{
	int exec = 0;

	if (strcmp(args[0], "setenv") == 0)
	{
		exec = setenv_builtin(args);
	}
	else if (strcmp(args[0], "unsetenv") == 0)
	{
		exec = unsetenv_builtin(args);
	}
	else if (strcmp(args[0], "cd") == 0)
	{
		exec = builtin_cd(args);
	}
	else if (strcmp(args[0], "exit") == 0)
	{
		if (args[1] != NULL)
		{
			int exit_status = _atoi(args[1]);

			free(env_path);
			builtin_exit(exit_status);
		}
		else
		{
			free(env_path);
			builtin_exit(0);
		}
	}

	return (exec);
}

/**
 * builtin_cd - function to cd built-in
 * @args: array of arguments
 * Return: an integer value
 */
int builtin_cd(char *args[])
{
	char *new_dir, *cwd;

	if (args[1] == NULL || strcmp(args[1], "~") == 0)
	{
		new_dir = _getenv("HOME");
		if (new_dir == NULL)
		{
			_eputs("cd: HOME not set\n");
			return (1);
		}
	}
	else if (strcmp(args[1], "-") == 0)
	{
		new_dir = _getenv("OLDPWD");
		if (new_dir == NULL)
		{ _eputs("cd: OLDPWD not set\n");
			return (1);
		}
		_puts(new_dir), _putchar('\n');
	}
	else
		new_dir = args[1];
	if (chdir(new_dir) != 0)
	{
		_eputs("cd: No such file or directory\n");
		return (1);
	}
	cwd = getcwd(NULL, 0);
	if (cwd == NULL)
	{
		_eputs("cd: Error updating PWD\n");
		return (1);
	}
	if (setenv("PWD", cwd, 1) != 0)
	{
		_eputs("cd: Error updating PWD environment variable\n"), free(cwd);
		return (1);
	}
	free(cwd);
	return (0);
}

