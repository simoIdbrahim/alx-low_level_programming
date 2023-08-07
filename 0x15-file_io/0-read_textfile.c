#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - main function
 * @filename: arg one
 * @letters: arg two
 * Return: number int || NULL
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	char *bufer;
	ssize_t f;
	ssize_t str;
	ssize_t title;

	f = open(filename, O_RDONLY);
	if (f == -1)
		return (0);

	bufer = malloc(sizeof(char) * letters);
	title = read(f, bufer, letters);
	str = write(STDOUT_FILENO, bufer, title);

	free(bufer);
	close(f);
	return (str);
}
