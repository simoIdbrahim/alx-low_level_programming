#include <stdio.h>


/**
 * main - Entry point
 *
 * Description: prints all possible combinations of single-digit numbers
 *
 * Return: Alawys 0 (Success)
*/

int main(void)
{
	int digit = 0;

	while (digit <= 9)
	{
		putchar(digit + 48);

		if (digit != 9)
			putchar(',');
			putchar(' ');
		digit++;
	}
	putchar('\n);

	return (0);
}
