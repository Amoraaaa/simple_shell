#include "main.h"

/**
 * _isalpha - Checks whether if input is an alphabetic character
 *
 * @a: character to be checked
 *
 * Return: 1 if char is alphabetic, 0 otherwise
*/

int _isalpha(int a)
{
	/** Check if the ASCII value of 'a' is within the range of lowercas */
	if ((a >= 97 && a <= 122) || (a >= 65 && a <= 90))
		return (1); /** Return 1 if 'a' is an alphabetic character */
	return (0); /** Return 0 if 'a' is not an alphabetic character */
}

/**
 * _strstr - locates a substring in a given string
 *
 * @b: input string to search in
 * @c: substring to search for
 *
 * Return: a pointer to the beginning of the substring if found
 * or NULL if not found
*/

char *_strstr(char *b, char *c)
{
	int d = 0, e = 0, tmpD = 0;

	while (b[d] != '\0')
	{
		/** Check if characters in 'b' and 'c' match */
		while (b[tmpD] == c[e] && c[e] != '\0')
		{
			e++;
			tmpD++;
		}

		/** If characters in 'c' found in 'b', return point in 'b' */
		if (c[e] == '\0')
			return (b + d);

		d++;
		tmpD = d;
		e = 0;
	}
	return (NULL); /** Return NULL if no substring 'c' is found in 'b' */
}

/**
 * _strrchr - locates a character in a string
 *
 * @f: input string
 * @g: character to search for
 *
 * Return: returns a pointer to the first occurrence of g
 * or NULL if g is not found
*/

char *_strrchr(char *f, char g)
{
	int h = _strlen(f);

	if (g == '\0')
		return (f + h);

	h--;

	while (*(f + h) != '\0')
	{
		if (*(f + h) == g)
			return (f + h + 1);

		h--;
	}

	return (NULL);
}

/**
 * _strpbrk - searches a string for any of a set of bytes
 *
 * @i: input string
 * @j: set of bytes used for searching
 *
 * Return: a pointer to the byte in i that matches one
 * of the bytes in accept
 * Or NULL if no matches
*/

char *_strpbrk(char *i, char *j)
{
	int Ocnt = 0, Pcnt = 0;

	while (*(i + Ocnt) != '\0')
	{
		Pcnt = 0;
		while (*(j + Pcnt) != '\0')
		{
			if (*(j + Pcnt) == *(i + Ocnt))
				return (i + Ocnt);
			Pcnt++;
		}

		Ocnt++;
	}
	return ('\0');
}

/**
 * _strdup - allocates space in memory and fills it with the specified string
 *
 * @k: string to fill the allocated space with
 *
 * Return: a pointer to char to the newly created space
*/

char *_strdup(char *k)
{
	char *dup;
	int cnt = 0, l = 0;

	/** If 'k' is NULL, return NULL */
	if (k == NULL)
		return (NULL);

	/** Get length of 'k' */
	while (k[cnt])
		cnt++;

	/** Allocate memory for 'dup' */
	dup = malloc((sizeof(*dup) * cnt) + 1);

	/** If memory allocation fails, return NULL */
	if (dup == NULL)
		return (NULL);

	/** Copy characters from 'k' to 'dup' */
	for (; l < cnt; l++)
		dup[l] = k[l];

	dup[l] = '\0'; /** Null-terminate 'dup' */

	return (dup); /** Return pointer to newly allocate 'k' */
}
