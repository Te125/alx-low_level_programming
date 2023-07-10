#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

#define BUFFER_SIZE 1024

/**
 * print_error_and_exit - function to print error message and exit
 * @error_message: the error message
 * @exit_code: the exit code
 */
void print_error_and_exit(const char *error_message, int exit_code)
{
	dprintf(STDERR_FILENO, "%s\n", error_message);
	exit(exit_code);
}

/**
 * copy_file - function to copy the content of a file to another
 * @source_file: the source file
 * @destination_file: the destination file
 */
void copy_file(const char *source_file, const char *destination_file)
{
	int src, dest;
	ssize_t t, d;
	char buffer[BUFFER_SIZE];

	src = open(source_file, O_RDONLY);
	if (src == -1)
		print_error_and_exit("Error: Can't read from source file", 98);

	dest = open(destination_file, O_WRONLY | O_CREAT | O_TRUNC,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (dest == -1)
	{
		close(src);
		print_error_and_exit("Error: Can't write to destination file", 99);
	}

	while ((t = read(src, buffer, BUFFER_SIZE)) > 0)
	{
		d = write(dest, buffer, t);
		if (d == -1 || d != t)
		{
			close(src);
			close(dest);
			print_error_and_exit("Error: Failed to write to destination file", 99);
		}
	}

	if (t == -1)
	{
		close(src);
		close(dest);
		print_error_and_exit("Error: Failed to read from source file", 98);
	}

	if (close(src) == -1)
		print_error_and_exit("Error: Can't close source file descriptor", 100);

	if (close(dest) == -1)
		print_error_and_exit("Error: Can't close destination file descriptor", 100);
}

/**
 * main - entry point
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success, otherwise an error code
 */
int main(int argc, char *argv[])
{
	if (argc != 3)
		print_error_and_exit("Usage: cp file_from file_to", 97);

	copy_file(argv[1], argv[2]);

	return (0);
}
