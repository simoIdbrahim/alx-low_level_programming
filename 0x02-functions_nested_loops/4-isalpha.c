#include "main.h"

/**
 * _isalpha - checks if character is a letter both lowercase uppercase
 *
 * @c: takes input from other function.
 *
 * Return: 1 is c if trye else 0
*/

int _isalpha(int c)
{
	if (c >= 97 && <= 122)
		return (1);
	if (c >= 65 && c <= 90)
		return (1);
	return (0);
}
