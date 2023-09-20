#include "main.h"
/**
 * sigint_handler - event handler for (CTRL+C) sigint signal
 *
 * @a: signal
 *
 * Return: always void
*/

void sigint_handler(__attribute__((unused))int a)
{
	_putchar('\n');
	exit(130);
}
/**
 * _puts_not_found - prints a not_found error msg to stderr
 *
 * @b: executable file name
 * @c: command name
 * @d: error count
 *
 * Return: always void
*/

void _puts_not_found(char *b, char *c, unsigned int d)
{
	char *cnt = to_str(d);

	_puts_err(b);
	_puts_err(": ");
	_puts_err(cnt);
	_puts_err(": ");
	_puts_err(c);
	_puts_err(": not found\n");
	free(cnt);
	EXIT_STATUS = 127;
}
/**
 * args_split - splits a string into array of words
 *
 * @e: string to be splitted
 *
 * Return: pointer to the newly created array
*/

char **args_split(char *e)
{
	char *tok;
	char **words = NULL;
	int i = 0, count = 0;

	if (!e)
		return (NULL);

	count = count_words(e);
	words = malloc(sizeof(*words) * (count + 1));

	if (!words)
		return (NULL);

	tok = strtok(e, " ");
	while (tok && i < count)
	{
		words[i] = tok;
		i++;
		tok = strtok(NULL, " ");
	}

	words[i] = NULL;

	return (words);
}
/**
 * trim_string - trims the starting and trailing spaces from string
 *
 * @f: string to be trimmed
 *
 * Return: pointer to the trimmed string
*/

char *trim_string(char *f)
{
	int i = 0, isalpha = 0;
	char *ret = malloc(strlen(f) + 1);

	while (f[i])
	{
		if (!f[i + 1] && (f[i] == ' ' || f[i] == '\n'))
			break;
		if (_isalpha(f[i]))
		{
			isalpha = 1;
			ret[i] = f[i];
			i++;
		}
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
 * @g: string input
 *
 * Return: number of counted words
*/

unsigned int count_words(char *g)
{
	unsigned int len = 0, i = 0;

	while (g[i] != '\0')
	{
		if (g[i] == ' ')
			len++;
		i++;
	}

	return (len + 1);
}

