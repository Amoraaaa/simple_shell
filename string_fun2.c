#include "main.h"

/**
 * _strcat - concatenates two strings together
 *
 * @dest: input string where ouput is gonna be saved
 * @src: input string that's gonna be concatenated
 *
 * Return: a pointer to char pointed to string dest
 */

char *_strcat(char *dest, char *src)
{
	int i = 0;

	while (dest[i] != '\0')
		i++;

	while (*src != '\0')
	{
		dest[i] = *src;
		src++;
		i++;
	}

	dest[i] = '\0';

	return (dest);
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

/**
 * _isdigit - checks if input is digit or not
 *
 * @c: char to be checked
 *
 * Return: 1 if char is digit, 0 otherwise
 */

int _isdigit(int c)
{
	if (c >= 48 && c < 58)
		return (1);

	return (0);
}

/**
 * _strncat - concatenates two strings up to n characaters
 *
 * @dest: input string to which output is saved
 * @src: input string to be apended
 * @n: maximum number of characaters to be appended
 * Return: pointer to the new dest string
 */

char *_strncat(char *dest, char *src, int n)
{
	int i = 0, cnt = 0;

	while (dest[i] != '\0')
		i++;
	while (cnt < n && *src != '\0')
	{
		dest[i] = *src;
		src++;
		i++;
		cnt++;
	}

	dest[i] = '\0';

	return (dest);

}

/**
 * _strcmp - compares two strings
 *
 * @s1: first input string
 * @s2: second input string
 *
 * Return: an integer > 0 if s1 is greater than s2
 * < 0 if s1 is less than s2
 * or 0 if s1 equals s2
 */

int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (*(s1 + i) == *(s2 + i) && *(s1 + i) != '\0')
		i++;

	return (*(s1 + i) - *(s2 + i));
}

