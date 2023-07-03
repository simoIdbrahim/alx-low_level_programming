#include "main.h"

/**
 * _strpbrk - main function
 * @s: String
 * @accept: string to match
 *
 * Return: pointer to the byte
 */

char *_strpbrk(char *s, char *accept)
{
	int i, j;
	char *p;

	i = 0;

	while (s[i] != '\0')
	{
		j = 0;
		while (accept[j] != '\0')
		{
			if (accept[j] == s[i])
			{
				p = &s[i];
				return (0);
			}
			j++;
		}
		i++;
	}

	return (0);
}
