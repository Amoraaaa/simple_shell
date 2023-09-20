#include "main.h"

/**
 * main - The main function which acts as the entry point to the program.
 *
 * @argument_count: The number of command-line arguments passed to the program.
 * @argument_values: An array of character pointers representing the command
 *
 * Return: The function always returns 0 indicating successful execution.
*/

int main(__attribute__((unused))int argument_count, char *argument_values[])
{
	/*Call the shell function with the first argument*/
	shell(argument_values[0]);

	/* Return 0 to indicate successful execution*/
	return (0);
}

