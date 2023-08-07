#include "main.h"


/**
 * read_textfile - function that reads a text file & prints it to the POSIX standard output
 * @filename: file to read
 * @letters: number of letters to print
 *
 * Return: actual number of letters it could read and print
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t len, lent;
	char *buf;

	if (filename == NULL)
	{
		return (0);
	}
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		return (0);
	}
	buf = malloc(sizeof(char) * letters);
	if (buf == NULL)
	{
		close(fd);
		return (0);
	}
	len = read(fd, buf, letters);
	close(fd);
	if (len == -1)
	{
		free(buf);
		return (0);
	}
	lent = write(STDOUT_FILENO, buf, len);
	free(buf);
	if (len != lent)
	{
		return (0);
	}
	return (lent);
}
