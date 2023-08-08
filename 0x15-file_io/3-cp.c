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
	int file_f, file_t, err_c;
	ssize_t num, nwr;
	char buf[1024];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "%s\n", "Usage: cp file_from file_to");
		exit(97);
	}

	file_f = open(argv[1], O_RDONLY);
	file_t = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC | O_APPEND, 0664);
	error_f(file_f, file_t, argv);

	num = 1024;
	while (num == 1024)
	{
		num = read(file_f, buf, 1024);
		if (num == -1)
			error_f(-1, 0, argv);
		nwr = write(file_t, buf, num);
		if (nwr == -1)
			error_f(0, -1, argv);
	}

	err_c = close(file_f);
	if (err_c == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_f);
		exit(100);
	}

	err_c = close(file_t);
	if (err_c == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_f);
		exit(100);
	}
	return (0);
}
