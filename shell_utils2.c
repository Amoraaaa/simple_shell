#include "main.h"

/**
 * full_path - finds the full path of the command in env
 *
 * @args_zero: name of the command
 * @path: path variable from environ
 *
 * Return: same command if path already provided, found path
 */

char *full_path(char *args_zero, char *path)
{
	char *tok = NULL, *final_path = NULL;
	char *command = args_zero;

	if (access(args_zero, X_OK) != -1)
		return (command);

	if (!path)
		return (NULL);

	tok = strtok(path, ":");
	while (tok)
	{
		final_path = malloc(_strlen(tok) + _strlen(args_zero) + 2);
		_strcpy(final_path, tok);
		_strcat(final_path, "/");
		_strcat(final_path, command);

		if (access(final_path, X_OK) != -1)
			break;

		free(final_path);
		tok = strtok(NULL, ":");
	}

	if (!tok)
		return (NULL);

	return (final_path);
}

/**
 * _getenv - searches the env variable for the specified name
 *
 * @name: the name of env variable to search for
 *
 * Return: pointer to the found variable's values (FOUND), NULL
 */

char *_getenv(char *name)
{
	char **env = environ, *var;
	char *tok, *val = NULL;
	int i;

	for (i = 0; env[i]; i++)
	{
		var = _strdup(env[i]);
		tok = strtok(var, "=");

		if (_strcmp(tok, name) == 0)
		{
			tok = strtok(NULL, "=");

			if (!tok)
				break;

			val = malloc(sizeof(*val) * _strlen(tok) + 1);
			_strcpy(val, tok);
			free(var);
			break;
		}
		free(var);
	}
	return (val);
}


/**
 * builtin_exit - exit the shell with the specified status
 *
 * @status: the status to exit with
 *
 * Return: Always void
 */

void builtin_exit(int status)
{
	if (!status)
		exit(0);
	exit(status);
}

/**
 * print_env - prints the current environment
 *
 * Return: Always void
 */

void print_env(void)
{
	char **env = environ;

	while (*env)
	{
		_puts(*env ? *env : "(nil)");
		_puts("\n");
		env++;
	}
}

/**
 * check_command - checks if command is exit or ls
 * to execute specific operations
 *
 * @fpath: full path to the cmd
 * @args: array containing input arguments
 *
 * Return: an integer indicating the status after execution
 */

int check_command(char *fpath, char *args[])
{
	int i = 1, retStats = 0;
	DIR *dir = NULL;

	if (_strstr(fpath, "/bin/ls") && args[1])
	{
		while (args[i])
		{
			dir = opendir(args[i]);
			if (!dir && !starts_with(args[i], "-"))
			{
				retStats = DIR_NOT_FOUND;
				closedir(dir);
				break;
			}
			closedir(dir);
			i++;
		}
	}
	return (retStats);
}

