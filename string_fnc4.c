#include "main.h"

/**
 * to_str - converts a number to a string
 *
 * @n: number to be converted
 *
 * Return: a string representing the converted number
 */

char *to_str(unsigned int n)
{
	char *no;
	unsigned int i = 0, tmp = n, len = 0;

	while (tmp)
		tmp /= 10, len++;

	no = malloc((sizeof(*no) * len) + 1);
	if (!no)
		return (NULL);

	if (!(n % 10))
		no[i] = '0', n /= 10, i++;

	while (n)
	{
		no[i] = (n % 10) + '0';
		n /= 10;
		i++;
	}
	no[i] = '\0';
	rev_string(no);
	return (no);
}


/**
 * _eputs - prints a string to stderr
 *
 * @str: string to print
 *
 * Return: Always void
 */

void _eputs(char *str)
{
	int i = 0;

	while (str[i])
		_eputchar(str[i]), i++;
}

/**
 * _eputchar - prints a char to stderr
 *
 * @c: char to be printed
 *
 * Return: number of chars printed
 */

int _eputchar(char c)
{
	return (write(STDERR_FILENO, &c, 1));
}

/**
 * rev_string - reverses a string
 *
 * @s: string to be reversed
 *
 * Return: Always void
 */

void rev_string(char *s)
{
	int str_size = strlen(s), i;
	char *l = s, *r = (s + str_size - 1);
	char temp = *l, temp2 = *r;

	if (str_size == 0)
		return;
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
 * starts_with - finds if a string starts with a certain prefix
 *
 * @str: the string to test
 * @pre: the prefix
 *
 * Return: 0 (Fails), 1 (Succeeds)
 */

int starts_with(char *str, char *pre)
{
	int flag = 0, i = 0, j = 0;

	for (; str[i]; i++)
	{
		if (str[i] == pre[j])
			j++;
		else
			break;
	}

	if (j == _strlen(pre))
		flag = 1;

	return (flag);
}

