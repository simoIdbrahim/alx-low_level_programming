#include "main.h"

/**
 * _strchr - main function
 * @s: pointer to put the constant
 * @c: constant
 *
 * Return: pointer to s
 */

char *_strchr(char *s, char c)
{
	int i;

	for (i = 0; s[i] >= '\0' ; i++)
	{
		if (s[i] == c)
		{
			return (s + i);
		}
	}

	return ('\0');
}
