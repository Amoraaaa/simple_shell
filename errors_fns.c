#include "main.h"

/**
 * _exit - exit shell with specified status
 * @status:  exit status
 * Return: void
 */

void _exit(int status)
{
	/** check if status is null return 0 */
	if (!status)
		exit(0);
	/** exit with specified status */
	exit(status);
}

/**
 * invalid_exit - to prints invalid exit error
 * @prog_name: name of the running shell
 * @status: status of the program
 * @ctr: count of the command
 * Return: void
 */

void invalid_exit(char *prog_name, char *status, unsigned int ctr)
{
	char *count = to_str(ctr);

	_puts_err(prog_name);
	_puts_err(": ");
	_puts_err(count);

	_puts_err(": exit:");
	_puts_err(" Illegal Number: ");

	_puts_err(status);
	/** free the counter after finished */
	free(count);

	EXIT_STATUS = 2;
}

/**
 * perm_denied_err - prints permission denied error
 * @prog_name: running shell's name
 * @fname: file's name
 * @ctr: the count of the command
 * Return: Always void
 */

void perm_denied_err(char *prog_name, char *fname, unsigned int ctr)
{
	char *count = to_str(ctr);

	_puts_err(prog_name);
	_puts_err(": ");
	_puts_err(count);
	_puts_err(": ");
	_puts_err(fname);
	_puts_err(": Permission denied\n");

	/** free the counter after finished */
	free(count);

	EXIT_ST = 126;
}