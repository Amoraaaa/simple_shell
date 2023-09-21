#include "main.h"

/**
 * _strcpy - copies string 2 into string 1
 *
 * @dest: the string to be copied into
 * @src: the string to copy from
 *
 * Return: pointer to the copied string
 */

char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; *(src + i) != '\0'; i++)
	{
		dest[i] = *(src + i);
	}
	dest[i] = *(src + i);
	return (dest);
}

/**
 * _atoi - converts a string to an integer
 *
 * @s: string input to be converted
 *
 * Return: string s converted to an integer
 */

int _atoi(char *s)
{
	unsigned int num = -1;
	int sign = 1;

	do {
		if (*s == '-')
		sign *= -1;
		else if (*s >= '0' && *s <= '9')
			num = (num * 10) + (*s - '0');
		else if (num > 0)
			break;
	} while (s++);

	return (num * sign);
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */

int _putchar(char c)
{
	return (write(STDOUT_FILENO, &c, 1));
}

/**
 * _strlen - return the length of a string
 *
 * @s: string
 *
 * Return: the length of string s
 */

int _strlen(char *s)
{
	int len;

	for (len = 0; *s != '\0'; len++)
		s++;

	return (len);
}

/**
 * _puts - prints a string to stdout
 *
 * @str: string to be printed
 *
 * Return: Always void
 */

void _puts(char *str)
{
	int i = 0;

	while (str[i])
		_putchar(str[i]), i++;
}

