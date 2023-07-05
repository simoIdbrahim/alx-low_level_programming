#include "main.h"

/**
 * is_prime_number - main function
 * @othrn: int
 * @n: int
 * Return: 0 or 1
 */

int check_prime(int n, int othrn);
int is_prime_number(int n)
{
	return (check_prime(n, 2));
}

/**
 * check_prime - main function
 * @n: int
 * @othrn: int
 * Return: int
 */

int check_prime(int n, int othrn)
{
	if (othrn >= n && n > 1)
		return (1);

	else if (n % othrn == 0 || n <= 1)
		return (0);
	else
		return (check_prime(n, othrn + 1));
}
