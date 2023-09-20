#inchlude "main.h"

/**
 * _isdigit - checks if it's digit or not
 * @ch: charcter to be checked
 *
 * Return: 1 (success), 0 otherwise
 */

int _isdigit(int ch)
{
	if (ch >= 48 && ch < 58)
		return (1);

	return (0);
}

/**
 * _puts - function to prints a string
 * @str: string input
 *
 * Return: void
 */

void _puts(char *str)
{
	int k = 0;
	while (str[k])
		_putchar(str[k]), k++;
}

/**
 * _putchar - prints a character
 * @ch: The character to be printed
 *
 * Return: 1 (success), -1 otherwise
 */
int _putchar(char ch)
{
	return (write(STDOUT_FILENO, &ch, 1));
}

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
	int k = 0;

	/** compute the destination length*/
	while (dest[k] != '\0')
		k++;

	while (*src != '\0')
	{
		dest[k] = *src;
		src++;
		k++;
	}

	dest[k] = '\0';

	return (dest);
}

/**
 * _strncat - concatenates two strings up to n characaters
 * @dest: input string destination
 * @src: input string soucre
 * @n: number of characaters to be appended to string
 * Return: pointer to the new dest string
 */

char *_strncat(char *dest, char *src, int n)
{
	int count = 0, k = 0;

	/** compute the destination length*/
	while (dest[k] != '\0')
		k++;

	while (count < n && *src != '\0')
	{
		dest[k] = *src;
		src++;
		k++;
		count++;
	}

	dest[k] = '\0';

	return (dest);
}