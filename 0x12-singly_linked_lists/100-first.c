#include <stdio.h>

void firstConstructor(void) __attribute__ ((constructor));

/**
 * firstConstructor - main function
 */
void firstConstructor(void)
{
	printf("You're beat! and yet, you must allow,\n");
	printf("I bore my house upon my back!\n");
}

