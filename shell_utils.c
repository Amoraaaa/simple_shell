#include "main.h"

/**
 * trim_string - trims the starting and trailing spaces from string
 *
 * @str: string to be trimmed
 *
 * Return: pointer to the trimmed string
 */

char *trim_string(char *str)
{
	int i = 0, isalpha = 0;
	char *ret = malloc(strlen(str) + 1);

	while (str[i])
	{
		if (!str[i + 1] && (str[i] == ' ' || str[i] == '\n'))
			break;
		if (_isalpha(str[i]))
			isalpha = 1;
		ret[i] = str[i];
		i++;
	}
	ret[i] = '\0';
	if (!isalpha)
	{
		free(ret);
		return (NULL);
	}

	return (ret);
}

/**
 * count_words - counts the words in a string
 *
 * @str: string input
 *
 * Return: number of counted words
 */

unsigned int count_words(char *str)
{
	unsigned int len = 0, i = 0;

	while (str[i] != '\0')
	{
		if (str[i] == ' ')
			len++;
		i++;
	}

	return (len + 1);
}

/**
 * args_split - splits a string into array of words
 *
 * @str: string to be splitted
 *
 * Return: pointer to the newly created array
 */

char **args_split(char *str)
{
	char *tok;
	char **words = NULL;
	int i = 0, count = 0;

	if (!str)
		return (NULL);

	count = count_words(str);
	words = malloc(sizeof(*words) * (count + 1));

	if (!words)
		return (NULL);

	tok = strtok(str, " \t\n\r\f\v");
	while (tok && i < count)
	{
		words[i] = tok;
		i++;
		tok = strtok(NULL, " \t\n\r\f\v");
	}

	words[i] = NULL;

	return (words);
}

/**
 * _puts_not_found - prints a not_found error msg to stderr
 *
 * @prog_name: executable file name
 * @name: command name
 * @c: error count
 *
 * Return: always void
 */
void _puts_not_found(char *prog_name, char *name, unsigned int c)
{
	char *cnt = to_str(c);

	_eputs(prog_name);
	_eputs(": ");
	_eputs(cnt);
	_eputs(": ");
	_eputs(name);
	_eputs(": not found\n");
	free(cnt);
	EXIT_ST = 127;
}

/**
 * sigint_handler - event handler for (CTRL+C) sigint signal
 *
 * @sig: signal
 *
 * Return: always void
 */

void sigint_handler(__attribute__((unused))int sig)
{
	_putchar('\n');
	/* _puts(PROMPT); */
	/* EXIT_ST = 130; */
	exit(130);
}


