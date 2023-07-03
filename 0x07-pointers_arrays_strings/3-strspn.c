#include "main.h"

/**
 * _strspn - main function
 * @s: pointer to put the constant
 * @accept: constant
 * @n: length of src to be copied
 *
 * Return: unsigned int
 */

unsigned int _strspn(char *s, char *accept)
{
	unsigned int i, j;

	for (i = 0; s[i] != '\0'; i++)
	{
		for (j = 0; accept[j] != s[i]; j++)
		{
			if (accept[j] == '\0')
				return (i);
		}
	}
	return (i);
}
