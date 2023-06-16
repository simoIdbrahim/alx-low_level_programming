#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: prints the lowercase alphabet in reverse
 *
 * Return: Alawys 0 (Success)
*/

int main(void)
{
	int ch =  'z';

	while (ch >= 'a')
	{
		putchar(ch);
		ch--;
	}
	putchar('\n');

	return (0);
}
