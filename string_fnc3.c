#include "main.h"

/**
 * _strdup - allocates space in memory and fills it with the specified string
 *
 * @str: string to fill the allocated space with
 *
 * Return: a pointer to char to the newly created space
 */

char *_strdup(char *str)
{
	char *dup;
	int cnt = 0, i = 0;

	if (str == NULL)
		return (NULL);

	while (str[cnt])
		cnt++;

	dup = malloc((sizeof(*dup) * cnt) + 1);

	if (dup == NULL)
		return (NULL);

	for (; i < cnt; i++)
		dup[i] = str[i];

	dup[i] = '\0';

	return (dup);
}


/**
 * _strrchr - locates a character in a string
 *
 * @s: input string
 * @c: character to search for
 *
 * Return: returns a pointer to the first occurence of c
 * or NULL if c is not found
 */

char *_strrchr(char *s, char c)
{
	int i = _strlen(s);

	if (c == '\0')
		return (s + i);

	i--;

	while (*(s + i) != '\0')
	{
		if (*(s + i) == c)
			return (s + i + 1);

		i--;
	}

	return (NULL);
}

/**
 * _strpbrk - searches a string for any of a set of bytes
 *
 * @s: input string
 * @accept: set of bytes used for searching
n *
 * Return: a pointer to the byte in s that matches one
 * of the bytes in accept
 * Or NULL if no matches
 */

char *_strpbrk(char *s, char *accept)
{
	int Ocnt = 0, Pcnt = 0;

	while (*(s + Ocnt) != '\0')
	{
		Pcnt = 0;
		while (*(accept + Pcnt) != '\0')
		{
			if (*(accept + Pcnt) == *(s + Ocnt))
				return (s + Ocnt);
			Pcnt++;
		}

		Ocnt++;
	}
	return ('\0');
}

/**
 * _strstr - locates a substring in a given string
 *
 * @haystack: input string to search in
 * @needle: substring to search for
 *
 * Return: a pointer to the beggining of the substring if found
 * or NULL if not found
 */


char *_strstr(char *haystack, char *needle)
{
	int i = 0, j = 0, tmpI = 0;

	while (haystack[i] != '\0')
	{

		while (haystack[tmpI] == needle[j] && needle[j] != '\0')
		{
			j++;
			tmpI++;
		}

		if (needle[j] == '\0')
			return (haystack + i);

		i++;
		tmpI = i;
		j = 0;
	}
	return (NULL);
}

/**
 * _isalpha - Checks wether if input is alphabetic character
 *
 * @c: character to be checked
 *
 * Return: 1 if char is alphabetic, 0 otherwise
 */

int _isalpha(int c)
{
	if ((c >= 97 && c <= 122) || (c >= 65 && c <= 90))
		return (1);
	return (0);
}
