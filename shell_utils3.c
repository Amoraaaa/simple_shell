#include "main.h"

/**
 * _puts_invalid_exit - prints permission denied error
 *
 * @prog_name: name of the running shell
 * @status: status of the file
 * @c: count of the command
 *
 * Return: Always void
 */

void _puts_invalid_exit(char *prog_name, char *status, unsigned int c)
{
	char *cnt = to_str(c);

	_eputs(prog_name);
	_eputs(": ");
	_eputs(cnt);
	_eputs(": exit:");
	_eputs(" Illegal Number: ");
	_eputs(status);
	free(cnt);
	EXIT_ST = 2;
}

/**
 * _puts_denied - prints permission denied error
 *
 * @prog_name: name of the running shell
 * @name: name of the file
 * @c: count of the command
 *
 * Return: Always void
 */

void _puts_denied(char *prog_name, char *name, unsigned int c)
{
	char *cnt = to_str(c);

	_eputs(prog_name);
	_eputs(": ");
	_eputs(cnt);
	_eputs(": ");
	_eputs(name);
	_eputs(": Permission denied\n");
	free(cnt);
	EXIT_ST = 126;
}

