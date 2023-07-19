#include "function_pointers.h"

/**
 * print_name - main function.
 * @name: the string name
 * @f: the printing function pointer
 * Return: void
 */

void print_name(char *name, void (*f)(char *))
{
	if (name && f)
		f(name);
}
