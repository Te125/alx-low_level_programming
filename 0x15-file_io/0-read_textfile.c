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
	FILE *fp;
	char *buffer;
	size_t s, t;

	if (filename == NULL)
	{
		return (0);
	}

	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		return (0);
	}
	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
	{
		fclose(fp);
		return (0);
	}

	t = fread(buffer, sizeof(char), letters, fp);
	if (t == 0)
	{
		free(buffer);
		fclose(fp);
		return (0);
	}

	s = write(STDOUT_FILENO, buffer, t);
	if (s != t)
	{
		free(buffer);
		fclose(fp);
		return (0);
	}

	free(buffer);
	fclose(fp);
	return (s);
}
