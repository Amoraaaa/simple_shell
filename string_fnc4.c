#include "main.h"

/**
 * _puts_err - prints a string to stderr
 *
 * @a1: string to print
 *
 * Return: Always void
*/

void  _puts_err(char *a1)
{
	int b1 = 0;

	/* Loop through each character in the string */
	while (a1[b1])
	/* Print each character to stderr */
		_putchar_err(a1[b1]), b1++;
}

/**
 * starts_with - finds if a string starts with a certain prefix
 *
 * @a2: the string to test
 * @b2: the prefix
 *
 * Return: 0 (Fails), 1 (Succeeds)
 */
int starts_with(char *a2, char *b2)
{
	int flag = 0, i = 0, j = 0;

	/* Loop through each character in the string */
	for (; a2[i]; i++)
	{
		/* If the character matches, increment j */
		if (a2[i] == b2[j])
			j++;
		else
			break;
	}

	/* If all characters in the prefix were found in the string, set flag to 1 */
	if (j == _strlen(b2))
		flag = 1;

	return (flag);
}

/**
 * reverse_string - reverses a string
 *
 * @a3: string to be reversed
 *
 * Return: Always void
*/

void reverse_string(char *a3)
{
	int str_size = strlen(a3), i;
	char *l = a3, *r = (a3 + str_size - 1);
	char temp = *l, temp2 = *r;

	/* If the string is empty, return immediately */
	if (str_size == 0)
	return;

	/* Swap characters from both ends of the string until reaching the middle */
	for (i = 0; i < str_size / 2; i++)
	{
		*l = temp2;
		*r = temp;
		temp = *(l + 1);
		temp2 = *(r - 1);
		l++;
		r--;
	}
}

/**
 * to_str - converts a number to a string
 *
 * @a4: number to be converted
 *
 * Return: a string representing the converted number
 */
char *to_str(unsigned int a4)
{
	char *no;
	unsigned int i = 0, tmp = a4, len = 0;

	/* Calculate the number of digits in the number */
	while (tmp)
		tmp /= 10, len++;

	/* Allocate memory for the resulting string */
	no = malloc((sizeof(*no) * len) + 1);

	/* If memory allocation failed, return NULL */
	if (!no)
		return (NULL);

	/* If the number is zero, set the first character of the string to '0' */
	if (!(a4 % 10))
		no[i] = '0', a4 /= 10, i++;

	/* Convert each digit of the number to a character and add it to the string */
	while (a4)
	{
		no[i] = (a4 % 10) + '0';
		a4 /= 10;
		i++;
	}

	/* Add null terminator at the end of the string */
	no[i] = '\0';

	/* Reverse the string to get the correct order of digits */
	reverse_string(no);

	return (no);
}

/**
 * _putchar_err - prints a char to stderr
 *
 * @a5: char to be printed
 *
 * Return: number of chars printed
*/

int  _putchar_err(char a5)
{
	/* Write one character to stderr and return the number*/
	return (write(STDERR_FILENO, &a5, 1));
}

