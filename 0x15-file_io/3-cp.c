#include "main.h"
#include <stdio.h>

/**
 * error_f - prototype function.
 * @file_from: arg one
 * @file_to: arg two.
 * @argv: arg three.
 * Return: void.
 */

void error_f(int file_from, int file_to, char *argv[])
{
	if (file_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	if (file_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		exit(99);
	}
}

/**
 * main - main function
 * @argc: arg one.
 * @argv: arg two.
 *
 * Return: int 0.
 */

int main(int argc, char *argv[])
{
	int file_from, file_to, err_close;
	ssize_t num, nwr;
	char buf[1024];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "%s\n", "Usage: cp file_from file_to");
		exit(97);
	}

	file_from = open(argv[1], O_RDONLY);
	file_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC | O_APPEND, 0664);
	error_f(file_from, file_to, argv);

	num = 1024;
	while (num == 1024)
	{
		num = read(file_from, buf, 1024);
		if (num == -1)
			error_f(-1, 0, argv);
		nwr = write(file_to, buf, num);
		if (nwr == -1)
			error_f(0, -1, argv);
	}

	err_close = close(file_from);
	if (err_close == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_from);
		exit(100);
	}

	err_close = close(file_to);
	if (err_close == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_from);
		exit(100);
	}
	return (0);
}
