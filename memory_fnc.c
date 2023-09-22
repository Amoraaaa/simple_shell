#include "main.h"

/**
 * _calloc - allocates memory for an array using malloc initialized to 0
 *
 * @nmemb: number of elements to be allocated
 * @size: number of bytes to allocate for each element
 *
 * Return: a void pointer to the newly allocated space
 */

void *_calloc(unsigned int nmemb, unsigned int size)
{
	void *ptr;

	if (nmemb == 0 || size == 0)
		return (NULL);

	ptr = malloc((nmemb * size));

	if (ptr == NULL)
		return (NULL);

	_memset(ptr, 0, (nmemb * size));

	return (ptr);
}

/**
 * _realloc - reallocates the size of a memory block
 *
 * @ptr: pointer to the memory previously allocated by malloc
 * @old_size: size in bytes of the allocated space for ptr
 * @new_size: new size in bytes of the new memory block
 *
 * Return: a pointer to the newly reallocated size
 * NULL if new size equals old size
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *new_ptr;
	unsigned int i = 0, min = old_size < new_size ? old_size : new_size;

	if (old_size == new_size)
		return (ptr);

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	new_ptr = malloc(new_size);

	if (new_ptr == NULL)
		return (NULL);

	if (ptr == NULL)
		return (new_ptr);

	for (; i < min; i++)
		*((char *)new_ptr + i) = *((char *)ptr + i);

	free(ptr);

	return (new_ptr);
}

/**
 * afree - fress an array allocated
 *
 * @arr: array to be freed
 *
 * Return: Always void
 */

void afree(char **arr)
{
	int i = 0;

	while (arr[i])
		free(arr[i]);
}

/**
* _memset - fils the memory with a constant
*
* @s: memory area [array]
* @b: constant used to fill memory array
* @n: number of bytes to be filled
*
* Return: a pointer to the filled area s
*/

char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i = 0;

	for (; i < n; i++)
		*(s + i) = b;

	return (s);
}

/**
 * _memcpy - copies memory bytes from one area to another
 *
 * @dest: destination memory area
 * @src: source memory area
 * @n: number of bytes to be copied
 *
 * Return: pointer to dest area
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int cnt = 0;

	while (cnt < n)
	{
		*(dest + cnt) = *(src + cnt);
		cnt++;
	}

	return (dest);
}

