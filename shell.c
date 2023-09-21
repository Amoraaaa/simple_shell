#include "main.h"

/**
* main_shell - main shell function
*
* @x1: name of the executable file
*
* Return: 0 (Exit_Success), negative (Exit_Failure)
*/

int main_shell(char *x1)
{
	char *y1 = NULL, *z1 = NULL;
	unsigned int a1 = 0;
	int b1 = 0, c1 = 0;
	size_t d1 = 0;
	const int e1 = isatty(STDIN_FILENO);

	signal(SIGINT, sigint_handler);
	if (e1)
		_puts(PROMPT);

	while ((c1 = getline(&y1, &d1, stdin)) != -1)
	{
		if (y1)
		{
			a1++;
			z1 = trim_string(y1);

			if (z1 && _strcmp(z1, "exit") == 0)
				free(z1), free(y1), _exit(EXIT_STATUS);
			if (z1)
				b1 = shell_handler(z1);

			if (b1 == ERROR_NOT_FOUND)
				not_found_err(x1, z1, a1);
			else if (b1 == PERM_DENIED)
				perm_denied_err(x1, z1, a1);
			else
				EXIT_STATUS = b1;

			if (z1)
				free(z1);
		}
			if (e1)
				_puts(PROMPT);
	}
	free(y1);
	if (e1)
		_putchar('\n');
	exit(EXIT_STATUS);
}

/*
* @f: array of arguments from the stdin
* @g: environment of the current running process
* @h: environment path
*
* Return: 0 (Success), negative number (Failure)
*/
int execute_command(char *f[], char *g[], char *h)
{
	pid_t i = -1;
	int j, k = 0, l;
	char *m = full_path(f[0], h);

	k = check_command(m, f);
	if (!m)
		return (ERROR_NOT_FOUND);

	l = access(m, F_OK);
	if (l != -1)
		i = fork();
	else
		return (ERROR_NOT_FOUND);

	if (i == -1)
		k = ERROR_NOT_FOUND;
	else if (i == 0)
	{
		if (execve(m, f, g) != -1)
		{
			if (errno == EACCES)
				exit(PERM_DENIED);
			exit(1);
		}
	}
	else
	{
		waitpid(i, &j, 0);
		if (WIFEXITED(j) && WEXITSTATUS(j) == PERM_DENIED)
		{
			if (_strcmp(m, f[0]) != 0)
				free(m);
			return (PERM_DENIED);
		}
	}

	if (_strcmp(m, f[0]) != 0)
		free(m);

	return (k);
}

/**
* shell_handler - process the inputs before running it
*
* @n: command from stdin before preprocessing
*
* Return: 0 (Success), negative number (Failure)
*/
int shell_handler(char n[])
{
	char *o[BUFF_SIZE], **p, *q;
	int r = 0, s = 0;

	p = split_args(n);
	if (!p)
		return (ERROR_NO_SPLIT);

	q = _get_env(PATH);

	while (p[s])
		o[s] = p[s], s++;

	o[s] = NULL;
	free(p);

	if (_strcmp(o[0], "env") == 0)
	{
		print_env();
		free(q);
		return (r);
	}

	r = execute_command(o, __environ, q);
	free(q);

	return (r);
}

