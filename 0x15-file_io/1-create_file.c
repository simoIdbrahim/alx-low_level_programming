#include "main.h"

/**
 * create_file - main function
 * @filename: arg one
 * @text_content: arg two
 * Return: samthing.
 */

int create_file(const char *filename, char *text_content)
{
	int f, word, length = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (length = 0; text_content[length];)
			length++;
	}

	f = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	word = write(f, text_content, length);

	if (f == -1 || word == -1)
		return (-1);

	close(f);

	return (1);
}
