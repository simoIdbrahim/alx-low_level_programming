#include "main.h"

/**
 * *_strncpy - main function
 *
 * @dest: pointer to destnation input
 * @src: pointer to source input
 * @n: most number of bytes
 *
 * Return: @dest
*/

char *_strncpy(char *dest, char *src, int n)
{
	int i;

	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[i] = src[i];

	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}

	return (dest);
}
