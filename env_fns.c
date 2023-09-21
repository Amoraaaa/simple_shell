#include "main.h"

/**
 * _get_env - searching for the environment variable for the specified name
 * @env_name: env variable's name to search for
 *
 * Return: pointer to found variable's values or NULL
 */

char *_get_env(char *env_name)
{
	char *str_tok, *env_val = NULL;
	char **env = environ, *var;
	int i = 0;

	while (env[i])
	{
		var = _strdup(env[i]);
		str_tok = strtok(var, "=");
		if (_strcmp(str_tok, env_name) == 0)
		{
			str_tok = strtok(NULL, "=");

			/** if str_tok is null then braek */
			if (!str_tok)
				break;

			env_val = malloc(sizeof(*env_val) * _strlen(str_tok) + 1);

			/** copy  str_tok to env_val */
			_strcpy(env_val, str_tok);

			/** free the variable then break */
			free(var);
			break;
		}
		free(var);
		i++;
	}
	return (env_val);
}

/**
 * print_env - print current environment
 * Return: void
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

