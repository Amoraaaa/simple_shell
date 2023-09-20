#include "main.h"

/**
 * check_command - checks if command is exit or ls
 * to execute specific operations
 * @fpath: the full path to the CMD
 * @args: is array containing-input-arguments
 * Return: the status after the execution
 */

int check_command(char *fpath, char *args[])
{
	DIR *dir = NULL;
	int i = 1, status = 0;

	if (_strstr(fpath, "/bin/ls") && args[1])
	{
		/** while args are not null */
		while (args[i])
		{
			/** open the directory */
			dir = opendir(args[i]);
			/** checks if directory found in that path */
			if (!starts_with(args[i], "-") && !dir)
			{
				status = DIR_NOT_FOUND;
				closedir(dir);
				break;
			}
			/** close the directory after finish*/
			closedir(dir);
			i++;
		}
	}

	return (status);
}

/**
 * full_path - Finds the full path of the command in the env
 * @arg_zero: command's name
 * @path: path variable from the environmwent
 * Return: the found path (success), same command (fail)
 */

char *full_path(char *arg_zero, char *path)
{
	char *command = arg_zero;
	char *tok_str = NULL, *final_path = NULL;

	/** if file has no access return the same command */
	if (access(arg_zero, X_OK) != -1)
		return (command);

	if (!path)
		return (NULL);

	tok_str = strtok(path, ":");

	while (tok_str)
	{
		final_path = malloc(_strlen(tok_str) + _strlen(arg_zero) + 2);

		_strcpy(final_path, tok_str);
		_strcat(final_path, "/");
		_strcat(final_path, command);

		/** if file has no access return the same command */
		if (access(final_path, X_OK) != -1)
			break;

		free(final_path);
		tok_str = strtok(NULL, ":");
	}

	/** check if tok_str is null */
	if (!tok_str)
		return (NULL);

	return (final_path);
}