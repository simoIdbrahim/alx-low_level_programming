#include "main.h"

char *create_buffer(char *file);
void close_file(int fd);

/**
 * create_buffer - main function.
 * @file: arg one
 * Return: new buffer
 */

char *create_buffer(char *file)
{
	char *b;

	b = malloc(sizeof(char) * 1024);

	if (b == NULL)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", file);
		exit(99);
	}

	return (b);
}

/**
 * close_file - function two.
 * @fd: arg one.
 */

void close_file(int fd)
{
	int ca;

	ca = close(fd);

	if (ca == -1)
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
}

/**
 * main -functio three.
 * @argc: arg one.
 * @argv: arg two.
 *
 * Return: 0 if true.
 */

int main(int argc, char *argv[])
{
	int from, t, remove, w;
	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buffer = create_buffer(argv[2]);
	from = open(argv[1], O_RDONLY);
	remove = read(from, buffer, 1024);
	t = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (from == -1 || remove == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", argv[1]);
			free(buffer);
			exit(98);
		}

		w = write(t, buffer, remove);
		if (t == -1 || w == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", argv[2]);
			free(buffer);
			exit(99);
		}

		remove = read(from, buffer, 1024);
		t = open(argv[2], O_WRONLY | O_APPEND);

	} while (remove > 0);

	free(buffer);
	close_file(from);
	close_file(t);

	return (0);
}
