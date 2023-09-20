#include "main.h"

/**
 * _memcpy - copies memory bytes from one area to another
 *
 * @a: destination memory area
 * @b: source memory area
 * @c: number of bytes to be copied
 *
 * Return: pointer to dest area
 */
char *_memcpy(char *a, char *b, unsigned int c)
{
	unsigned int d = 0;

	/* Loop until we've copied 'c' bytes */
	while (d < c)
	{
		/* Copy each byte from source to destination */
		*(a + d) = *(b + d);
		/* Increment the counter */
		d++;
	}

	/* Return the destination pointer */
	return (a);
}

/**
* _memset - fills the memory with a constant
*
* @e: memory area [array]
* @f: constant used to fill memory array
* @g: number of bytes to be filled
*
* Return: a pointer to the filled area s
*/
char *_memset(char *e, char f, unsigned int g)
{
	unsigned int h = 0;

	/* Loop until we've filled 'g' bytes */
	for (; h < g; h++)
		/* Fill each byte of the memory area with the constant */
		*(e + h) = f;

	/* Return the pointer to the memory area */
	return (e);
}

/**
 * afree - frees an array allocated
 *
 * @i: array to be freed
 *
 * Return: Always void
 */
void afree(char **i)
{
	int j = 0;

	/* Loop until we've freed all elements of the array */
	while (i[j])
		/* Free each element of the array */
		free(i[j]);
}

/**
 * _calloc - allocates memory for an array using malloc initialized to 0
 *
 * @k: number of elements to be allocated
 * @l: number of bytes to allocate for each element
 *
 * Return: a void pointer to the newly allocated space
 */
void *_calloc(unsigned int k, unsigned int l)
{
	void *m;

	/* If no elements or size is zero, return NULL */
	if (k == 0 || l == 0)
		return (NULL);

	m = malloc((k * l)); /* Allocate memory for 'k' elements of 'l' bytes each */

	if (m == NULL) /* If allocation failed, return NULL */
		return (NULL);

	_memset(m, 0, (k * l)); /* Initialize all bytes of the newly allocated memory to zero */

	return (m); /* Return the pointer to the newly allocated memory */
}

/**
 * _realloc - reallocates the size of a memory block
 *
 * @n: pointer to the memory previously allocated by malloc
 * @o: size in bytes of the allocated space for ptr
 * @p: new size in bytes of the new memory block
 *
 * Return: a pointer to the newly reallocated size or NUL
 */
void *_realloc(void *n, unsigned int o, unsigned int p)
{
	void *q;
	unsigned int r = 0, s = o < p ? o : p; /* Determine the smallest of old and new sizes */

	if (o == p) /* If old size equals new size, return original pointr */
		return (n);

	if (p == 0 && n != NULL) /* If new size is zero and ptr is not NULL, */
	{
		free(n);
		return (NULL);
	}

	q = malloc(p); /* Allocate a new block of 'p' bytes */

	if (q == NULL) /* If allocation failed, return NULL. */
		return (NULL);

	if (n == NULL) /* If original pointer is NULL, return new pointer. */
		return (q);

	for (; r < s; r++) /* Copy 's' bytes from original block to new block. */
		*((char *)q + r) = *((char *)n + r);

	free(n); /* Free original block. */

	return (q); /* Return pointer to newly allocated block. */
}

