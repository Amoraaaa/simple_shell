#include "main.h"

/**
 * _strlen - return'str strtring length
 *
 * @str: input strtring
 *
 * Return: the length of strtring str
 */

int _strlen(char *str)
{
	int len;

	for (len = 0; *str != '\0'; len++)
		str++;

	return (len);
}

/**
 * _strcpy - copy strtring 2 into strtring 1.
 *
 * @dest: the strtring to be copied into
 * @src: the strtring to copy from
 *
 * Return: pointer to the copied strtring
 */

char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; *(src + i) != '\0'; i++)
		dest[i] = *(src + i);

	/** get lastrt char */
	dest[i] = *(src + i);
	return (dest);
}

/**
 * _strcmp - compares two strings
 *
 * @str1: first input string
 * @str2: second input string
 *
 * Return: an integer > 0 if s1 is greater than s2
 * < 0 if s1 is less than s2
 * or 0 if s1 equals s2
 */

int _strcmp(char *str1, char *str2)
{
	int i = 0;

	while (*(str1 + i) == *(str2 + i) && *(str1 + i) != '\0')
		i++;

	return (*(str1 + i) - *(str2 + i));
}

/**
 * _atoi - converts a string to an integer
 *
 * @str: string input to be converted
 *
 * Return: string str converted to an integer
 */

int _atoi(char *str)
{
	int _sign = 1;
	unsigned int num = -1;

	do {
		/** check the sign of the number */
		if (*str == '-')
			_sign *= -1;
		else if (*str >= '0' && *str <= '9')
			num = (num * 10) + (*str - '0');
		else if (num > 0)
			break;
	} while (str++);

	return (num * _sign);
}

/**
 * _strncpy - copies a string into another string up to n chars maximum
 *
 * @dest: string where content is to be copied
 * @src: string to be copied
 * @n: maximum number of chars to be copied
 *
 * Return: returns a pointer at string dest after copying
 */

char *_strncpy(char *dest, char *src, int n)
{
	int i = 0;

	while (i < n && *src != '\0')
	{
		dest[i] = *src;
		i++;
		src++;
	}

	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}

	return (dest);
}

